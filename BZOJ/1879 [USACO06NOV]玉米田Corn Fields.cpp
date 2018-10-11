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

const int maxn = 15;

int n, m, ans, flag;
int a[maxn][maxn], f[maxn][1 << 12];

bool check(int k, int x) {
	for (int i = 1; i <= m; i++)
		if ((x & (1 << (i - 1))) && ((x & (x >> 1)) || (!a[k][i])))
			return false;
	return true;
}

int main() {
//	freopen("INPUT", "r", stdin);

	read(n), read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
//	for (int x = 0; x < 1 << m; x++)
//		f[1][x] = check(1, x) ? 1 : 0;
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int x = 0; x < 1 << m; x++)
			if (check(i, x))
				for (int y = 0; y < 1 << m; y++)
					if (check(i - 1, y)) {
						flag = true;
						for (int j = 1; j <= m; j++)
							if ((x & (1 << (j - 1))) && (y & (1 << (j - 1)))) {
								flag = false;
								break;
							}
						if (flag) {
//							printf("%d -> %d : %d\n", y, x, f[i - 1][y]);
//							for (int t = x, i = 1; i <= m; i++)
//								putc('0' + (t & 1)), t >>= 1; putc('\n');
//							for (int t = y, i = 1; i <= m; i++)
//								putc('0' + (t & 1)), t >>= 1; putc('\n');
							f[i][x] += f[i - 1][y];
						}
					}
	}
//	for (int x = 0; x < 1 << m; x++) {
//		for (int t = x, i = 1; i <= m; i++)
//			putc('0' + (t & 1)), t >>= 1;
//		printf(" %d ", check(2, x));
//		putc(':'), putc(' ');
//		for (int i = 1; i <= n; i++)
//			print(f[i][x]);
//		puts("");
//	}
	ans = 0;
	for (int x = 0; x < 1 << m; x++)
		ans += f[n][x];
	print(ans % 100000000, '\n');

	return 0;
}

