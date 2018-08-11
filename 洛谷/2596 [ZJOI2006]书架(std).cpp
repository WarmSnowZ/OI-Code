#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;

int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}

void print(int x)
{
    if(x<0){putchar('-');x=-x;}
    if(x>9)print(x/10);
    putchar(x%10+'0');
}

int n,m,rt;
int v[100010],pos[100010],size[100010];
int ch[100010][2],fa[100010],sz;
char ss[20];

void update(int p)
{
    size[p]=size[ch[p][0]]+size[ch[p][1]]+1;
}

void rotate(int& p,int x) { 
    int y=fa[x],z=fa[y]; 
    int t=(ch[y][0]==x);
    if(y==p) p=x; 
    else if(ch[z][0]==y) ch[z][0]=x; 
    else ch[z][1]=x;  
    fa[y]=x; fa[ch[x][t]]=y; fa[x]=z;  
    ch[y][t^1]=ch[x][t]; ch[x][t]=y;   
    update(y);update(x);  
} 

void splay(int& p,int x) 
{   
    while(x!=p) 
    {
        int y=fa[x],z=fa[y];
        if(y!=p) 
        {
            if((ch[y][0]==x)^(ch[z][0]==y)) rotate(p,x);
            else rotate(p,y);
        }
        rotate(p,x);
    }
}

void ins(int x)
{
    v[++sz]=x; pos[x]=sz;
    size[sz]=1; ch[sz][0]=ch[sz][1]=0;
    if (sz>1)
    {
        ch[sz-1][1]=sz;fa[sz]=sz-1;
        splay(rt,sz);
    }
}

int find(int p,int k)
{
	printf("FIND %d %d\n", p, k);
    int ss=size[ch[p][0]];
    if(ss+1==k) return p;
    else if(ss>=k) return find(ch[p][0],k);
    else return find(ch[p][1],k-ss-1); 
}

void top_bottom(int d)
{
    int x=read(),y; x=pos[x];
    splay(rt,x);//ָ��Ԫ����ת����
    if(!ch[x][d]) return;//��1�����
    if(!ch[x][d^1]) {ch[x][d^1]=ch[x][d]; ch[x][d]=0; return;}//��2�����

    if(d==0) y=find(rt,size[ch[x][0]]+2);//Ԫ���ö����ҵ����ĺ��
    else y=find(rt,size[ch[x][0]]);//Ԫ���õף��ҵ�����ǰ��
    fa[ch[rt][d]]=y;//�ϲ�����
    ch[y][d]=ch[rt][d];
    ch[rt][d]=0;
    splay(rt,y);//��չ��֤���Ӷ�
}

void change()
{
    int x=read(),d=read(),y; if(d==0) return;//d=0ֱ�Ӻ���
    splay(rt,pos[x]);//ָ��Ԫ����ת����
    if(d==1) y=find(rt,size[ch[pos[x]][0]]+2);//Ԫ����ǰ���ҵ���ǰ��
    else y=find(rt,size[ch[pos[x]][0]]);//Ԫ���ú��ҵ�����
    int tv=v[y],tpos=pos[x];//������Ϣ
    printf(">>> %d %d\n", pos[x], y);
    printf(">>> %d %d %d %d\n", pos[x], pos[tv], v[tpos], v[y]);
    swap(pos[x],pos[tv]);
    swap(v[tpos],v[y]);
    printf(">>> %d %d %d %d\n", pos[x], pos[tv], v[tpos], v[y]);
}

int get()
{
    int x=read(); x=pos[x];
    splay(rt,x);
    printf(">>> %d\n", x);
    return size[ch[x][0]];
}

int main()
{
	freopen("INPUT", "r", stdin);
    n=read();m=read();rt=1;
    for(int i=1;i<=n;++i)
    {
        int x=read();ins(x);
    }

    while(m--)
    {
        scanf("%s",&ss);
    	printf("=== %c ===\n", ss[0]);
    	for (int i = 1; i <= n; i++)
    		printf("%d ", pos[i]);
    	puts("");
    	for (int i = 1; i <= n; i++)
    		printf("%d ", v[i]);
    	puts("");
    	for (int i = 1; i <= n; i++)
    		printf("%d ", size[i]);
    	puts("");
    	for (int i = 1; i <= n; i++)
    		printf("%d ", fa[i]);
    	puts("");
    	for (int i = 1; i <= n; i++)
    		printf("%d ", ch[i][0]);
    	puts("");
    	for (int i = 1; i <= n; i++)
    		printf("%d ", ch[i][1]);
    	puts("");
        if(ss[0]=='T') top_bottom(0);
        else if(ss[0]=='B') top_bottom(1);
        else if(ss[0]=='I') change();
        else if(ss[0]=='A') print( get() ),putchar('\n');
        else if(ss[0]=='Q') print( v[ find(rt,read()) ] ),putchar('\n');
    }

    return 0;
    //niiick
}
