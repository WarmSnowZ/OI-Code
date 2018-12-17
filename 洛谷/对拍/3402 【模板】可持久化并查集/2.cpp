#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define rg register int
#define ll long long
#define RG register
#define il inline
using namespace std;

il int gi() 
{
    rg x=0,o=0;RG char ch=getchar();
    while(ch!='-'&&(ch<'0'||'9'<ch)) ch=getchar();
    if(ch=='-') o=1,ch=getchar();
    while('0'<=ch&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return o?-x:x;
}

#define SZ 200010
int n,m,fa[SZ*30],deep[SZ*30];
// deep ��������
// fa �� һ������ĳ���汾�ĸ���

struct Tree {
  int l,r;
}tr[SZ*30];
#define lson tr[rt].l
#define rson tr[rt].r
int Ed[SZ],tot; 
// Ed �ǰ汾�� �� tot�ǽڵ���������Щ������ϯ������

void build(int &rt,rg l,rg r)
{
    rt=++tot;
    if(l==r)
    {
        fa[rt]=l;  // ��ʼ�汾 �� �������Լ�
        // ���񲢲鼯��ʼ��ÿ����ĸ��������Լ�
        return;
    }
    rg mid=l+r>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
}

// ��ϯ��ά������ ÿһ���汾 ÿһ����ĸ�����˭
void update(int &rt,rg last,rg l,rg r,rg pos,rg ff) //��pos�ĸ��׸ĳ�ff
{
    rt=++tot;
    if(l==r)
    {
        fa[rt]=ff;
        deep[rt]=deep[last];  // deep ���� ����ʽ�ϲ�
        return;
    }
    lson=tr[last].l;rson=tr[last].r;
    rg mid=l+r>>1;
    if(pos<=mid) update(lson,tr[last].l,l,mid,pos,ff);
    else update(rson,tr[last].r,mid+1,r,pos,ff);
}

int query(rg rt,rg l,rg r,rg pos) // ѯ��ĳһ���汾��һ����ĸ���
{
    if(l==r) return rt;
    rg mid=l+r>>1;
    if(pos<=mid) return query(lson,l,mid,pos);
    else return query(rson,mid+1,r,pos);
}

void add(rg rt,rg l,rg r,rg pos) // ��ĳһ�����鼯��ͨ����ÿһ�������ȼ�һ
{
    if(l==r) 
    {
        ++deep[rt];
        return;    
    }
    rg mid=l+r>>1;
    if(pos<=mid) add(lson,l,mid,pos);
    else add(rson,mid+1,r,pos);
}

int find_fa(rg ed,rg x) // ed �汾���
{ 
    rg ff=query(ed,1,n,x);  // ��ѯ����һ�汾�� һ����ĸ���
    if(x==fa[ff]) return ff;
    return find_fa(ed,fa[ff]);  // ����·��ѹ���Ĳ��鼯
}

int main() 
{
	freopen("3.txt","r",stdin);
	freopen("2.txt","w",stdout);
    n=gi(),m=gi();
    build(Ed[0],1,n);
//init
    for(rg opt,k,a,b,i=1;i<=m;++i) 
    {
        opt=gi();
        if(opt==1) 
        {
            Ed[i]=Ed[i-1];
            a=gi(),b=gi();
            rg f1=find_fa(Ed[i],a);
            rg f2=find_fa(Ed[i],b);
            if(fa[f1]==fa[f2]) continue;
            if(deep[f1]>deep[f2]) swap(f1,f2); 
            // �Ѵ����С�� ������֤f1���ӽڵ���һ����С�ڵ���f2
            update(Ed[i],Ed[i-1],1,n,fa[f1],fa[f2]);   // ��f1 
            if(deep[f1]==deep[f2]) add(Ed[i],1,n,fa[f2]);
          // ��Ϊf2 ������ f1 ����f1�����Ҫ��1
          //������ ����ʽ�ϲ� ����֤ ���鼯�ϲ��ĸ��Ӷ�
        }
        if(opt==2) 
        {
            k=gi();
            Ed[i]=Ed[k];
        }
        if(opt==3) 
        {
            Ed[i]=Ed[i-1];
            a=gi(),b=gi();
            rg f1=find_fa(Ed[i],a);
            rg f2=find_fa(Ed[i],b);
            if(fa[f1]==fa[f2]) puts("1");
            else puts("0");
        }
    }
  return 0;
}
