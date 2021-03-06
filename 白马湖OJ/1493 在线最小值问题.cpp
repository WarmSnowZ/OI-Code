// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

int h;
template <typename T> inline void read(T &x) {
	x = h = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) {
		if (ch == 'E') {
			h = 1;
			return;
		}
		if (ch == '.') {
			h = 2;
			return;
		}
		fl ^= ch == '-';
	}
	x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (ch == '.') {
		h = 2;
	}
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

int n, x;
std::multiset < int > set;

int main() {
	while (h ^ 2) {
		read(x);
		if (h == 1) {
			print(*set.begin());
			set.erase(set.begin());
		} else
			set.insert(x);
	}
	putc('\n');
	return 0;
}

