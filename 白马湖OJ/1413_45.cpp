#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
struct Zhan
{
	int n[3 * MAXN];
	int t;
}cal, a, b;
int _pri[256]; 
int push(Zhan &z, int c)
{
	z.n[z.t++] = c;
}
int pop(Zhan &z)
{
	return z.n[--z.t];
}
int main()
{
	_pri['+'] = 1;
	_pri['*'] = 2;
	cal.t = 0;
	a.t = 0;
	b.t = 0;
	int n;
	scanf("%d%*c", &n);
	int k = 0;
	char ccc[MAXN], cc[MAXN], c[MAXN], ch;
	scanf("%s", ccc);
	//���� 
	for (int i = 0; i < strlen(ccc); i++)
	{
		ch = ccc[i];
		if (ch == '(') cc[k++] = ch;
		else if (cc[k - 1] == ')') cc[k++] = ch;
		else 
		{
			if (cc[k - 1] != '_') cc[k++] = '_';
			cc[k++] = ch;
		}
	}
	if (cc[k - 1] != ')' && cc[k - 1] != '_') cc[k++] = '_';
	//for (int i = 0; i < k; i++) printf("%c", cc[i]); printf("\n");
	//��׺ת��׺ 
	int kk = k;
	char temp;
	k = 0;
	for (int i = 0; i < kk; i++)
	{
		ch = cc[i];
		if (ch == '_')
		{
			c[k++] = '_';
		}
		else if (ch == '+' || ch == '*') 
		{
			if (k == 0 || cal.n[cal.t - 1] == '(') push(cal, ch);
			else if (_pri[ch] > _pri[cal.n[cal.t - 1]]) 
			{	
				push(cal, ch);
			}
			else 
			{
				while (_pri[ch] <= _pri[cal.n[cal.t - 1]]) 
					c[k++] = pop(cal);
				push(cal, ch);
			}
		}
		else if (ch == '(') push(cal, ch);
		else if (ch == ')')
		{
			while (cal.t > 0)
			{
				temp = pop(cal);
				if(temp == '(') break;
				else c[k++] = temp;
			}
		}
	}
	while (cal.t > 0) c[k++] = pop(cal);
	//for (int i = 0; i < k; i++) printf("%c", c[i]); printf("\n");
	//����
	int ta0, ta1, tb0, tb1;
	for (int i = 0; i < k; i++)
	{
		ch = c[i];
		if (ch == '_') 
		{
			push(a, 1);
			push(b, 1);
		}
		else 
		{
			ta0 = pop(a);
			ta1 = pop(b);
			tb0 = pop(a);
			tb1 = pop(b);
			if(ch == '*')
			{
				push(a, (ta0 * tb1 + ta1 * tb0 + ta0 * tb0) % 10007);
				push(b, (ta1 * tb1) % 10007);
			}
			else if(ch == '+')
			{
				push(a, (ta0 * tb0) % 10007);
				push(b, (ta0 * tb1 + ta1 * tb0 + ta1 * tb1) % 10007);
			}
		}
	}
	printf("%d", pop(a) % 10007);
	return 0;
}
