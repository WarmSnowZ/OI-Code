// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
	while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 50010, maxm = 200010, maxe = 250010, inf = 1e9;

int n, m, u, v, w, cnt, ans = inf;
std::multiset < int > set;
int ch[maxe][2], fa[maxe], val[maxe], pto[maxe], rev[maxe];

struct edge {
	int u, v, w;
} e[maxm];
bool cmp(edge a, edge b) {
	return a.w < b.w;
}

bool isRoot(int x) { return ch[fa[x]][0] ^ x && ch[fa[x]][1] ^ x; }
bool getSon(int x) { return ch[fa[x]][1] == x; }

void update(int x) {
	pto[x] = x;
	if (pto[ch[x][0]] && val[pto[ch[x][0]]] < val[pto[x]]) pto[x] = pto[ch[x][0]];
	if (pto[ch[x][1]] && val[pto[ch[x][1]]] < val[pto[x]]) pto[x] = pto[ch[x][1]];
}

void rotate(int x) {
	if (!x || !fa[x]) return;
	int f = fa[x], fson = getSon(x);
	int ff = fa[f], ffson = getSon(f);
	int y = ch[x][fson ^ 1];
	if (!isRoot(f)) ch[ff][ffson] = x;
	fa[y] = f, fa[f] = x, fa[x] = ff;
	ch[f][fson] = y, ch[x][fson ^ 1] = f;
	update(f), update(x);
}

void cleanUp(int x) {
	if (!isRoot(x))
		cleanUp(fa[x]);
	if (rev[x]) {
		std::swap(ch[x][0], ch[x][1]);
		rev[ch[x][0]] ^= 1;
		rev[ch[x][1]] ^= 1;
		rev[x] = 0;
	}
}

void splay(int x) {
	cleanUp(x);
	while (!isRoot(x)) {
		int f = fa[x];
		if (!isRoot(f))
			rotate(getSon(x) == getSon(f) ? f : x);
		rotate(x);
	}
	update(x);
}

void access(int x) { for (int y = 0; x; y = x, x = fa[x]) splay(x), ch[x][1] = y, update(x); }
void mroot(int x) { access(x), splay(x), rev[x] ^= 1; }
void link(int x, int y) { mroot(x), fa[x] = y, update(y); }
int getRoot(int x) { access(x), splay(x); while (ch[x][0]) x = ch[x][0]; return x; }
void split(int x, int y) { mroot(x), access(y), splay(y); }
void cut(int x, int y) { split(x, y), fa[x] = ch[y][0] = 0, update(y); }

int main() {
//	freopen("INPUT", "r", stdin);

	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(e[i].u);
		read(e[i].v);
		read(e[i].w);
	}
	std::sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m + n; i++)
		pto[i] = i;
	for (int i = 1; i <= n; i++)
		val[i] = inf;
	for (int i = 1; i <= m; i++)
		val[i + n] = e[i].w;
	for (int i = 1; i <= m; i++) {
		u = e[i].u, v = e[i].v, w = e[i].w;
		if (u == v) continue;
//		printf("=== %d %d %d ===\n", u, v, w);
		if (getRoot(u) == getRoot(v)) {
//			printf("replace with a new edge\n");
			split(u, v);
			int t = pto[v] - n;
			cut(e[t].u, t + n), cut(t + n, e[t].v);
			link(u, i + n), link(i + n, v);
			set.erase(set.find(e[t].w)), set.insert(e[i].w);
		} else {
//			printf("add a new edge\n");
			link(u, i + n);
			link(i + n, v);
			set.insert(e[i].w);
			cnt++;
		}
		if (cnt == n - 1) {
//			printf("%d %d %d\n", *set.begin(), w, ans);
			ans = std::min(ans, w - *set.begin());
		}
	}
	print(ans, '\n');

	return 0;
}
