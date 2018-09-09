// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 52;
int n, m, a[maxn][maxn], f[maxn][maxn][maxn][maxn];

int main() {
	memset(f, 63, sizeof(f));
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read();
	f[1][1][1][1] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int p = 1; p <= n; p++)
				for (int q = 1; q <= m; q++)
					if ((!(i == p && j == q)) || (i == n && j == m))
						f[i][j][p][q] = min(min(
							f[i - 1][j][p - 1][q],
							f[i][j - 1][p][q - 1]
						), min(
							f[i][j - 1][p - 1][q],
							f[i - 1][j][p][q - 1]
						)) + a[i][j] + a[p][q];
	printf("%d\n", f[n][m][n][m]);
	return 0;
}

