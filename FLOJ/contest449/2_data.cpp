#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

int n, m;
int rand(int x) { return ::rand() % x + 1; }

void main() {
	srand(time(0) + clock());
	n = m = 10000;
	printf("%d %d\n", n ,m);
	for (int i = 2; i <= n; i++)
		printf("%d %d\n", rand(i - 1), i);
	for (int i = 1; i <= m; i++) {
		int l = 1;
		int r = rand(n);
		if (l > r) std::swap(l, r);
		printf("%d %d\n", l, r);
	}
}

} int main() { return ringo::main(), 0; }
