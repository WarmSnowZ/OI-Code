// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#include <windows.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

int brand() {
	return (rand() << 16) + (rand() << 1) + (rand() & 1);
}

int main() {
	freopen("3.txt", "w", stdout);
	srand(GetTickCount());
	
	int n = 5, m = 5;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++)
		printf("%d ", brand() % 100 + 1);
	for (int i = 1; i <= m; i++) {
		int l = brand() % n + 1;
		int r = brand() % n + 1;
		if (l > r) swap(l, r);
		printf("%d %d\n", l, r);
	}

	return 0;
}
