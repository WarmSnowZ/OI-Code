����԰��ҳ�������ϵ���� ����
��� - 769  ���� - 1  ���� - 69
NOIPSB�����+SB��DAY2
���߹�צ
��Ŀ����
С Q ��һ���ᰮ��צ�����ߣ� ��ϲ�������߱ڵĸо��� ��һ��С Q ����һ����ϰʹ�ù�
צ�ĺõط�������������������֡�
�������컨����Ա�����Ϊһ����������ᣬ ��ʼС Q ���� ԭ���ϡ� �������� N ����
��Ϊ������Բ����С Q ʵ�ֹ�צ�ƶ����������Ϊ��С Q ���Խ���צ�ҵ�Բ���ϣ���������
����Բ������ ��ԳƵ�λ�á�����С Q �� 3��Բ���� 7����С Q ����ͨ����Բ���ƶ��� 11��
����һ�������ѵ���С Q������ж��Լ��ܷ񵽴�ĳ�������أ�

�����ʽ
��һ���������� N,M����ʾԲ����������ѯ������
������һ�й� N ����������ÿ��Բ��������(���ظ�)
������ M ��ÿ�а���һ����������ѯ��

�����ʽ
�� M �ж�Ӧ M ��ѯ�ʣ���С Q ���ƶ���Ŀ��㣬��� Yes��������� No

����
2 2
1 3
3
4

No
Yes
���ݷ�Χ
���� 30%�����ݣ�M��N��10�������������ֵ��С�� 1000��
���� 60%�����ݣ�M��N��5000��
���� 100%�����ݣ�M��N��100000�������������ֵ��С�� [Math Processing Error]��
����д�˸�60��������Ȼ����ȥдT2��Ȼ���Բе�YES��NO���ȫ��д��
��ͼѡ����ʽ�ӿɵ����ɵ�����������Ϊ[Math Processing Error], xΪ��ǰ������ô
��ʼ����Ϊԭ�㣬��ô���������ǿ϶����ܵ����QAQ
���ݹ����������Լ���չŷ��������ԭ���֪�����ҽ���Ŀ��Ϊgcd�ı���ʱ�н⡣
��Ԥ�����ȫ�����ܵ�2(a[j]-a[i])����������Լ�������ж�Ŀ���Ƿ�Ϊgcd�ı������ɸ��Ӷ�N^2����60��
ͨ��ŷ������㷨������������������֪gcd(a,b)=gcd(a-b,b)��
��p1={2(a[i]-a[1])|i>1}�����Լ������p2={2(a[i]-a[j])}�����Լ������֪p1>=p2����Ϊp1��p2Լ�����ɣ�
����������i,j����p1ͬʱ��2(a[i]-a[1])��2(a[j]-a[1])��Լ������ôp1Ҳһ��������2(a[i]-a[1])-2(a[j]-a[1])=2*(a[i]-a[j])��Լ������p1<=p2����������p1=p2��
�����Ͳ���ҪN^2����ͬʱ��gcd�ˣ�ֻ��p1���ɣ��ɻ�����֡�
code��

#include<cstdio> 
#include<iostream>
#include<algorithm> 
using namespace std;
const int maxn = 2000007; 
#define LL long long
int n,m,cnt=0;
LL a[maxn];
LL g;
LL gcd(LL x,LL y) {
    if(y==0)return x;
    else return gcd(y,x%y);
}
int main () {

    int c1=0,c2=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        LL aa;
        scanf("%lld",a+i);
    }
    g=2*(a[1]-a[2]);
    for(int i=1;i<=n;i++) g=gcd(g,2*(a[i]-a[1]));
    for(int i=1;i<=m;i++) {
        LL q;
        scanf("%lld",&q);
        if((q%g+g)%g==0&&q%2==0)puts("Yes");
        else puts("No");
    }
    return 0;
}
ѡ����Ϸ
��Ŀ����
����������������Ϸ����������ǰ��!�����ų�һ�ţ������Ұ� 1 ��!��š�ÿ������һ
�������ɸ���Ȩֵ�� ÿһ�֣� �����ѡ��һ������[Math Processing Error]�����������������ڵ��������Ȩֵ
����һ��ֵ[Math Processing Error]�� ���߽��������������ڵ��������Ȩֵ����Ϊ���෴���� �����������!����
��ѡ��k�����������ĵ÷�Ϊ��k�����Ȩֵ�ĳ˻���
����ÿ�ζ��ܿ����ҳ��÷����ŵ�ѡ�򷽰��������������룬����������Ϸ�Ѷȡ���ÿ
�λ�ѡ��һ������[Math Processing Error],Ȼ��ѯ�ʻ��������������ѡ��[Math Processing Error]��������з����ĵ�
��֮�͡�
���¿ɰѻ����ѵ��ˣ����ǻ����ҵ��˴������㡣���ܰ�����
�������з����ĵ÷�֮�Ϳ��ܴܺ���ֻ��Ҫ����÷�֮�Ͷ�[Math Processing Error]ȡģ
�Ľ�������������[Math Processing Error]��ɷǸ��������ɡ�

�����ʽ
���ļ�game.in �ж������ݡ�
�����һ�а�������������!,1���ֱ��ʾ��ĸ���������Ĳ���������
������һ�а���!���ո��������������ʾÿ�����ʼ��Ȩֵ��
������1�У�ÿ�б�ʾ�����һ��������
���������硰[Math Processing Error]�������ʾ���㽫�������[Math Processing Error]���������Ȩֵ��������c��
���������硰[Math Processing Error]�������ʾ���㽫�������[Math Processing Error]���������Ȩֵ����Ϊ�����෴����
���������硰[Math Processing Error]�������ʾ������Ҫ�ش��[Math Processing Error]��ѡ��k���������ȡ�򷽰��ĵ÷�֮�͡�

�����ʽ
����ļ���[Math Processing Error]�С�
�������㱦����ÿһ��ѯ�ʲ��������һ�У���ʾ��ѯ�ʵĴ𰸡�

����
10 9
3 6 7 4 6 1 6 7 2 6
3 5 7 3
1 1 7 -9
1 2 3 5
3 2 6 1
2 5 8
3 5 7 3
2 2 3
3 1 10 2
3 1 2 2

36
999999996
72
999999885
12
������˵����
��һ��ѯ�ʣ�[Math Processing Error]
�ڶ���ѯ�ʣ�
ѯ��ǰ�������ȨֵΪ��[Math Processing Error]
[Math Processing Error]
[Math Processing Error]
������ѯ�ʣ�
ѯ��ǰ�������ȨֵΪ��[Math Processing Error]
[Math Processing Error]
��������
�������������ֲ������ݵ��ص㡣������ڽ����Ŀ�����������ѣ����Գ���ֻ���һ
���ֲ������ݡ�ÿ�����Ե�Ĺ�ģ���ص����±�



#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long 
inline int read() {
    int x=0,f=1;
    char cc=getchar() ;
    while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();};
    while(cc<='9'&&cc>='0')x=x*10+cc-'0',cc=getchar();return x*f;
}
const int maxn = 0007;
const int mod = 1000000007;
int n,m;
LL tree[maxn<<2][15],a[maxn],lazy1[maxn<<2],lazy2[maxn<<2];
LL C[maxn][25];
inline void merge(int rt) 
{
    for(int i=0;i<=10;++i) 
    {
        tree[rt][i]=0;
        for(int j=0;j<=i;j++) 
            tree[rt][i]=(tree[rt][i]+tree[rt<<1][j]*tree[rt<<1|1][i-j]%mod)%mod;
    }
}
void update(int l,int r,int rt,int w) 
{
    int len=(r-l)+1;
    LL tmp[11];
    for(int i=0;i<=10;i++)tmp[i]=tree[rt][i]%mod;
    for(int i=1;i<=10;i++) 
    {
        tree[rt][i]=0;
        LL t=1;
        for(int j=0;j<=i;++j) 
        {
            LL tt=tmp[i-j]%mod*C[len-(i-j)][j]%mod*t%mod;
            tree[rt][i]=(tree[rt][i]+tt)%mod;
            t=(t%mod)*(w%mod)%mod;
        }
    }
    return ;
} 
void pushdown(int l,int r,int rt) 
{
    int mid=(l+r)>>1;
    if(lazy1[rt]) 
    {
        if(lazy2[rt<<1])lazy1[rt<<1]=(lazy1[rt<<1]+mod-lazy1[rt])%mod;
        else lazy1[rt<<1]=(lazy1[rt<<1]+lazy1[rt])%mod;
        if(lazy2[rt<<1|1])lazy1[rt<<1|1]=(lazy1[rt<<1|1]+mod-lazy1[rt])%mod;
        else lazy1[rt<<1|1]=(lazy1[rt<<1|1]+lazy1[rt])%mod;
        update(l,mid,rt<<1,lazy1[rt]);
        update(mid+1,r,rt<<1|1,lazy1[rt]);
        lazy1[rt]=0;
    }
    if(lazy2[rt])
     {
        for(int i=1;i<=10;i+=2) 
        {
            tree[rt<<1][i]=mod-tree[rt<<1][i];
            tree[rt<<1|1][i]=mod-tree[rt<<1|1][i];//��ת 
        }
        lazy2[rt]=0;
        lazy2[rt<<1]^=1;
        lazy2[rt<<1|1]^=1;
    }
}
void build(int l,int r,int rt) 
{
    if(l==r) 
    {
        for(int i=0;i<=10;i++)tree[rt][i]=0;
        tree[rt][0]=1;
        tree[rt][1]=(a[l]%mod+mod)%mod;
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    merge(rt);
}
void modify1(int l,int r,int rt,int tl,int tr,int tw) 
{
    if(tl<=l&&tr>=r) 
    {
        if(lazy2[rt])lazy1[rt]=(lazy1[rt]+mod-tw)%mod;//�з�ת���ʱ��ȥ 
        else lazy1[rt]=(lazy1[rt]+tw)%mod;
        update(l,r,rt,tw);return ;
    }
    pushdown(l,r,rt);
    int mid=(l+r)>>1;
    if(tl<=mid)modify1(l,mid,rt<<1,tl,tr,tw);
    if(tr>mid)modify1(mid+1,r,rt<<1|1,tl,tr,tw);
    merge(rt);
    return ;
}

void modify2(int l,int r,int rt,int tl,int tr) 
{
    if(tl<=l&&tr>=r) 
    {
        for(int i=1;i<=10;i+=2)tree[rt][i]=mod-tree[rt][i];//��ת����
        lazy2[rt]^=1;
        return ;
    }
    pushdown(l,r,rt);
    int mid=(l+r)>>1;
    if(tl<=mid)modify2(l,mid,rt<<1,tl,tr);
    if(tr>mid)modify2(mid+1,r,rt<<1|1,tl,tr);
    merge(rt);
}
struct Node{
    LL f[14];
};
Node calc(Node lc,Node rc) 
{
    Node o;
    o.f[0]=1;
    for(int i=1;i<=10;i++) 
    {
        o.f[i]=0;
        for (int j=0;j<=i;j++)
            o.f[i]=(o.f[i]+lc.f[j]*rc.f[i-j]%mod)%mod;
    }
    return o;
}
Node query(int l,int r,int rt,int tl,int tr) 
{
    if(tl<=l&&tr>=r) 
    {
        Node a;
        for(int i=0;i<=10;++i)a.f[i]=tree[rt][i];
        return a;
    }
    int mid=(l+r)>>1;
    pushdown(l,r,rt);
    if(tr<=mid)return query(l,mid,rt<<1,tl,tr);
    if(tl>mid)return query(mid+1,r,rt<<1|1,tl,tr);
    Node lc=query(l,mid,rt<<1,tl,tr);
    Node rc=query(mid+1,r,rt<<1|1,tl,tr);
    return  calc(lc,rc);
}

int main () 
{
    n=read(),m=read();
    C[0][0]=1;
    for (int i=1;i<=n;i++) 
    {
        C[i][0]=1;
        for (int j=1;j<=10;j++) 
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    for(int i=1;i<=n;i++)a[i]=read();
    build(1,n,1);
    for(int id,a,b,c;m--;) 
    {
        id=read(),a=read(),b=read();
        if(id==1) 
        {
            c=read();modify1(1,n,1,a,b,c);
        }
        else if(id==2) 
        {
            modify2(1,n,1,a,b);
        }
        else if(id==3) 
        {
            c=read();
            Node tmp=query(1,n,1,a,b);
            printf("%d\n",(tmp.f[c]+mod)%mod);
        }
    }
}
/*
10 9
3 6 7 4 6 1 6 7 2 6
3 5 7 3
1 1 7 -9
1 2 3 5
3 2 6 1
2 5 8
3 5 7 3
2 2 3
3 1 10 2
3 1 2 2
36
999999996
72
999999885
12
*/
std����Ȼ������д��QAQ

#include <cstdio>
#include <cstdlib>
#define MOD 1000000007
#define N 100005
typedef long long LL; 
using namespace std;
struct Node {
    LL f[11];
}node[N * 4];
LL a[N], lazy1[N * 4];
bool lazy2[N * 4];
LL C[N][11];

Node merge(Node lc, Node rc) {
    Node o;
    o.f[0] = 1;
    for (int i = 1; i <= 10; i++) {
        o.f[i] = 0;
        for (int j = 0; j <= i; j++)
            o.f[i] = (o.f[i] + lc.f[j] * rc.f[i - j] % MOD) % MOD;
    }
    return o;
}

void build(int o, int l, int r) {
    if (l == r) {
        for (int i = 0; i <= 10; i++) node[o].f[i] = 0;
        node[o].f[0] = 1;
        node[o].f[1] = (a[l] % MOD + MOD) % MOD;
        return ;
    }
    int mid = (l + r) >> 1;
    build(o * 2, l, mid);
    build(o * 2 + 1, mid + 1, r);
    node[o] = merge(node[o * 2], node[o * 2 + 1]);
    return ;
}

void update1(int o, int l, int r, int c) {
    int len = r - l + 1;
    LL ff[11];
    for (int i = 0; i <= 10; i++) ff[i] = node[o].f[i];
    for (int i = 1; i <= 10; i++) {
        node[o].f[i] = 0;
        LL t = 1;
        for (int j = 0; j <= i; j++) {
            LL tmp = ff[i - j] * C[len - (i - j)][j] % MOD * t % MOD;
            node[o].f[i] = (node[o].f[i] + tmp) % MOD;
            t = t * c % MOD;
        }
    }
    return ;
}

void push_down(int o, int l, int r) {
    int mid = (l + r) >> 1;
    if (lazy1[o]) {
        if (lazy2[o * 2])
            lazy1[o * 2] = (lazy1[o * 2] + MOD - lazy1[o]) % MOD;
        else 
            lazy1[o * 2] = (lazy1[o * 2] + lazy1[o]) % MOD;
        if (lazy2[o * 2 + 1])
            lazy1[o * 2 + 1] = (lazy1[o * 2 + 1] + MOD - lazy1[o]) % MOD;
        else 
            lazy1[o * 2 + 1] = (lazy1[o * 2 + 1] + lazy1[o]) % MOD;
        update1(o * 2, l, mid, lazy1[o]);
        update1(o * 2 + 1, mid + 1, r, lazy1[o]);
        lazy1[o] = 0;
    }
    if (lazy2[o]) {
        lazy2[o * 2] ^= 1;
        lazy2[o * 2 + 1] ^= 1;
        for (int j = 1; j <= 10; j += 2) {
            node[o * 2].f[j] = MOD - node[o * 2].f[j];
            node[o * 2 + 1].f[j] = MOD - node[o * 2 + 1].f[j];
        }
        lazy2[o] = 0;
    }
}

void modify1(int o, int l, int r, int ll, int rr, int c) {
    if (ll <= l && rr >= r) {
        if (lazy2[o]) lazy1[o] = (lazy1[o] + MOD - c) % MOD;
        else lazy1[o] = (lazy1[o] + c) % MOD;
        update1(o, l, r, c);
        return ;
    }
    int mid = (l + r) >> 1;
    push_down(o, l, r);
    if (ll <= mid) modify1(o * 2, l, mid, ll, rr, c);
    if (rr > mid) modify1(o * 2 + 1, mid + 1, r, ll, rr, c);
    node[o] = merge(node[o * 2], node[o * 2 + 1]);
    return ;
}

void modify2(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) {
        for (int i = 1; i <= 10; i += 2) node[o].f[i] = MOD - node[o].f[i];
        lazy2[o] ^= 1;
        return ;
    }
    int mid = (l + r) >> 1;
    push_down(o, l, r);
    if (ll <= mid) modify2(o * 2, l, mid, ll, rr);
    if (rr > mid) modify2(o * 2 + 1, mid + 1, r, ll, rr);
    node[o] = merge(node[o * 2], node[o * 2 + 1]);
    return ;
}

Node query(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) 
        return node[o];
    int mid = (l + r) >> 1;
    push_down(o, l, r);
    if (rr <= mid) return query(o * 2, l, mid, ll, rr);
    if (ll > mid) return query(o * 2 + 1, mid + 1, r, ll, rr);
    Node lc = query(o * 2, l, mid, ll, rr);
    Node rc = query(o * 2 + 1, mid + 1, r, ll, rr);
    return merge(lc, rc);
}

int main(int argc, char ** argv) {
    //freopen("game.in", "r", stdin);
    //freopen("game.out", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= 10; j++) 
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    for (int i = 1; i <= n; i++) 
        scanf("%d", &a[i]);
    build(1, 1, n); 
    for (int i = 1; i <= m; i++) {

        int l, r, opt;
        scanf("%d%d%d",&opt, &l, &r);
        if (opt == 1) {
            int c;
            scanf("%d", &c);
            c = (c % MOD + MOD) % MOD;
            modify1(1, 1, n, l, r, c);
        }
        else if (opt == 2) {
            modify2(1, 1, n, l, r);
        }
        else {
            int k;
            scanf("%d", &k);
            Node o = query(1, 1, n, l, r);
            printf("%d\n", o.f[k] % MOD);
        }
    }
    return 0;
}
����������
��Ŀ����
����ʱ�֣�T���У԰��ɫ�ʰ�쵡�У԰�ľ�ɫ���Ա�����[Math Processing Error]���㣬ÿ����ᱻ����һ��[Math Processing Error]��[Math Processing Error]֮���������
��ʾ�����������͡�У԰����İ��ͨ����һ����������һʱ���ھ���1.Ȼ������ʼ���������������ĳʱ�����ڵ�i������
������һʱ�̣��������Ը���[Math Processing Error]�ƶ�������[Math Processing Error]����֤[Math Processing Error]����������N��ʱ��֮�󣬴�����
�����������ľ�������ȫ������������������õ�һ������ΪN������[Math Processing Error]��[Math Processing Error]��ÿ��������[Math Processing Error]��[Math Processing Error]֮�䡣

���������о��������õ������еĸ��ʷֲ��������������п��ܵõ�������Ϊ[Math Processing Error]����
[Math Processing Error]
��ʾ���õ���������[Math Processing Error]�ĸ��ʡ�

��Ϊ�ܿ���[Math Processing Error]���ѧ����������Ȼ֪����[Math Processing Error]���������̽��S�ĸ��ʷֲ����ް�����
���ڣ�������������
[Math Processing Error]

�����ʽ
��һ��������[Math Processing Error]��[Math Processing Error]����ʾ��������ʹ����ܹ�Ҫ�ߵ�ʱ������������[Math Processing Error]�У�ÿ��[Math Processing Error]��������[Math Processing Error]�е�[Math Processing Error]������
��ʾ[Math Processing Error]���������ݱ�֤�������[Math Processing Error],[Math Processing Error]��������һ��һ������[Math Processing Error]����ʾ�����ǵ������顣
�ٽ�����һ��[Math Processing Error]��[Math Processing Error]��[Math Processing Error]֮�������һ�α�ʾÿ����������͡�

�����ʽ
һ�У���ʾ[Math Processing Error]��ֵ��������λС����

����
2 2
0.5 0.5
0.5 0.5
2
0 1

0.500000000
3 3
0.2 0.4 0.4
1 0 0
1 0 0
2
0 1 1

0.667200000
���ݷ�Χ
����[Math Processing Error]�����ݣ�[Math Processing Error]��
����[Math Processing Error]�����ݣ�[Math Processing Error]��
����[Math Processing Error]�����ݣ�[Math Processing Error]��

����: �������ݽṹ�����߶���,���ݽṹ
����Ҫ�� ��ע�� �ղظ���    
zzzzx
��ע - 65
��˿ - 50
+�ӹ�ע
1 0
? ��һƪ��luogu P2659 ����������
? ��һƪ�������
posted @ 2017-10-24 16:53 zzzzx �Ķ�(18) ����(0) �༭ �ղ�
ˢ������ˢ��ҳ�淵�ض���
ע���û���¼����ܷ������ۣ��� ��¼ �� ע�ᣬ������վ��ҳ��
����
 WRONG!
ҹ������������

�����ʹ�������������н�����ʻ 
 Another 11101001
�ǳƣ�zzzzx
԰�䣺1��5����
��˿��50
��ע��65
+�ӹ�ע
<	2018��9��	>
��	һ	��	��	��	��	��
26	27	28	29	30	31	1
2	3	4	5	6	7	8
9	10	11	12	13	14	15
16	17	18	19	20	21	22
23	24	25	26	27	28	29
30	1	2	3	4	5	6
����

 

 
��������
�ҵ����
�ҵ�����
�ҵĲ���
��������
�ҵı�ǩ
�ҵı�ǩ
ZZ(3)
��ʷ���
&���ܷ���(1)
AC�Զ���&fail��(7)
AtCoder(1)
bitset(1)
Burnside������polay����(2)
bzoj(131)
cdq����(4)
Codeforces(8)
Dijkstra(3)
Dp of Dp(1)
FFT(3)
hash(3)
KM�㷨(1)
Link cut tree(7)
loj(13)
lucas����(1)
NOIP����(3)
poj(4)
prufer����(1)
Splay(5)
STL(2)
st��(3)
tarjan(8)
treap(1)
trie�ֵ���(3)
Worth to review(23)
����(3)
������(1)
���Լ��(5)
��������(7)
����&΢/����(1)
��.��.��.ͼ�ϵķ���(8)
��̬�滮(107)
��̬�滮����������dp(9)
��̬�滮��������dp(15)
�Ž�ɸ(1)
����(3)
����ʣ��(1)
����ͼƥ��(2)
������(5)
�ֿ�(1)
�����滮(1)
���Ρ������ִ�(10)
����������(16)
��˹��Ԫ(7)
��׺����(6)
�����㷨����dfs����(21)
�����㷨��������bfs(9)
���㼸��(1)
����˷�(10)
�ӿӿӿӿ�(6)
ģ��(3)
ģ���˻�(5)
Ī����˹(12)
Ī��(5)
ŷ������(4)
����֮·(12)
�����˼·(2)
������dp(1)
Ⱥ��(3)
�ݳ�(3)
���ַ�(1)
ɨ����(1)
���ɺ���(4)
����ֱ��(1)
�����ʷ�(3)
����DP(7)
�������ݽṹ�������鼯(19)
�������ݽṹ������(5)
�������ݽṹ����������(7)
�������ݽṹ������״����(5)
�������ݽṹ�����߶���(35)
���ݽṹ(15)
����(32)
���ۡ�����չŷ�����(3)
���ۡ�ɸ��������(7)
��ѧ(53)
�ı��β���ʽ�Ż�(2)
�����������仯����(4)
�㷨�����ֿ�(1)
�㷨��������(3)
�㷨����̰��(12)
͹����&&(2)
ͼ��(45)
ͼ�ۡ���SPFA(13)
ͼ�ۡ�����������(12)
ͼ�ۡ����ڽӱ�(2)
ͼ�ۡ�����������(7)
ͼ�ۡ������·(8)
ͼ�ۡ�����С������(8)
������(24)
�߶����ϲ�(3)
���Դ���(4)
���Թ滮/�����η�(1)
���Ի�(5)
б���Ż�(2)
����(3)
�����Ӱ�(11)
ջ(10)
�й�ʣ�ඨ��(1)
��ϯ��(10)
�����ѧ(11)
�����(6)
��ƫ��(2)
��ʵ���
2018��9�� (19)
2018��8�� (45)
2018��7�� (54)
2018��6�� (33)
2018��5�� (34)
2018��4�� (29)
2018��3�� (16)
2018��2�� (41)
2018��1�� (9)
2017��12�� (37)
2017��11�� (33)
2017��10�� (48)
2017��9�� (6)
2017��8�� (28)
2017��7�� (71)
2017��6�� (65)
2017��5�� (71)
2017��4�� (81)
2017��3�� (49)
���
7uh(2)
������
����attack
����mjt
����SovietPower
����wcz
�ϴ�lyq
�ҵ���һ������
233!
��������
1. Re:bzoj4456: [Zjoi2016]������
@SovietPower����ÿ��Dijkstra��ʼ��ҪO(nm)����������û����ô����woc��˵��ô��ô��...�������ǹ���......
--zzzzx
2. Re:bzoj5068: �Ѻõ�����
@Rliffixed...
--zzzzx
3. Re:bzoj5068: �Ѻõ�����
Markdown ը��,@zzzzx
--Rlif
4. Re:bzoj4456: [Zjoi2016]������
ÿ��Dijkstra��ʼ��ҪO(nm)����������û����ô����
--SovietPower
5. Re:bzoj1037: [ZJOI2008]���վۻ�Party
@SovietPowerwoc������...
--zzzzx
�Ķ����а�
1. �κ�һ������1����Ȼ��n���ܿ��Բ�ֳ����ɸ�С��n����Ȼ��֮�͡�(981)
2. ŷ����·��ŷ��· ֮ һ�ʻ�����(700)
3. ������ͼ��ǿ��ͨ�������� ֮ Kosaraju�㷨(660)
4. ���ʲ�����(457)
5. Think twice, code once.(409)
�������а�
1. ��ѩDiary?(5)
2. �²��ͣ�11101001.com(4)
3. �б�ѩ������������پ���(4)
4. FFT&NTT&����ʽ���(4)
5. bzoj5248: [2018��ʡʡ������]һ˫ľ��(3)
�Ƽ����а�
1. ͼ���㷨 ���ݽṹģ��(5)
2. Think twice, code once.(4)
3. ����-GOD BLESS ALL OF YOU(3)
4. luogu P1972 [SDOI2009]HH������(2)
5. �б�ѩ������������پ���(2)
Copyright ?2018 zzzzx
