// ==============================
//  author: memset0
//  website: https://memset0.cn
//  date: 2018.08.06 14:15:20
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

ll readll() {
	long long x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 1e5 + 10;
int n;
ll a1, a2, b1, b2;

int main() {
	n = read();
	a1 = readll(), b1 = readll();
	for (int i = 2; i <= n; i++) {
		a2 = readlll(), b2 = read();
		
	}
	return 0;
}