#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define fo(a,b,c) for(int a=b;a<=c;a++)
#define go(a,b,c) for(int a=b;a>=c;a--)
int read(){
    int a=0,f=0;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-')f=1;
    for(;c>='0'&&c<='9';c=getchar())a=a*10+c-'0';
    return f?-a:a;
}
const int N=50001;
int tmp,a[N],p[1000001],ans[N],divi;
struct nod{int pla,pre,suc;}cg[N];
struct node{int l,r,t,bel;}ls[N];
int cmp(node a,node b){
    if(a.l/divi!=b.l/divi)return a.l/divi<b.l/divi;
    if(a.r/divi!=b.r/divi)return a.r/divi<b.r/divi;
    return a.t<b.t; 
}
int main(){
	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
    int n=read(),m=read(),ln=0,tn=0,l=1,r=0,t=0,num=0;
    fo(i,1,n)a[i]=read();
    fo(i,1,m){
        scanf("\n");
        if(getchar()=='R'){//��������޸����¼�޸ĵĵص㣬�޸�ǰ�����ֺ��޸ĺ������
            ++tn;cg[tn].pla=read(),cg[tn].suc=read();
            cg[tn].pre=a[cg[tn].pla];
            a[cg[tn].pla]=cg[tn].suc;
        } 
        else ls[++ln]=(node){read(),read(),tn,ln};
    }
    divi=ceil(exp((log(n)+log(tn))/3));//�ֿ��С
    go(i,tn,1)a[cg[i].pla]=cg[i].pre;
    sort(ls+1,ls+ln+1,cmp);
    fo(i,1,m){
    	printf("%d %d %d %d\n", ls[i].l/divi, ls[i].r/divi, ls[i].t, ls[i].bel);
        while(ls[i].l<l)num+=!p[a[--l]]++,tmp++;
        while(ls[i].l>l)num-=!--p[a[l++]],tmp++;
        while(ls[i].r>r)num+=!p[a[++r]]++,tmp++;
        while(ls[i].r<r)num-=!--p[a[r--]],tmp++;
        while(ls[i].t<t){
        	tmp++;
            int pla=cg[t].pla;
            if(l<=pla&&pla<=r)num-=!--p[a[pla]],tmp++;
            a[pla]=cg[t--].pre;
            if(l<=pla&&pla<=r)num+=!p[a[pla]]++,tmp++;
        };
        while(ls[i].t>t){
        	tmp++;
            int pla=cg[++t].pla;
            if(l<=pla&&pla<=r)num-=!--p[a[pla]],tmp++;
            a[pla]=cg[t].suc;
            if(l<=pla&&pla<=r)num+=!p[a[pla]]++,tmp++;
        };//t�ƶ�
        ans[ls[i].bel]=num;
    }
    printf("%d\n",tmp);
    fo(i,1,ln)printf("%d\n",ans[i]); 
    return 0;
}
