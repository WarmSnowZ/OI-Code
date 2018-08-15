#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+5;
const int INF=599518803;

int n,minn;
int opt,x;
int tim,sum_peo,leave_peo;
int add[N],sub[N];
struct Node
{
    Node *son[2];   //���Ҷ��ӣ�son[0]������ӣ�son[1]���Ҷ��� 
    int key;    //Ȩֵ 
    int heap_key;   //ά���ѵ�Ȩֵ 
    int key_cnt;    //�ڵ������ 
    int size;   //�����Ľڵ���� 
    int tim;    //����˾��ʱ�� 
    bool flag;  //�Ƿ����� 
}node[N];

typedef Node* Tree;
Tree now_node,root,null;

int read()
{
    char c=getchar();int num=0,f=1;
    for(;!isdigit(c);c=getchar())
        switch(c)
        {
            case 'I':return 1;
            case 'A':return 2;
            case 'S':return 3;
            case 'F':return 4;
            case '-':f=-1;
            default:
                break;
        }
    for(;isdigit(c);c=getchar())
        num=num*10+c-'0';
    return num*f;
}

void init()
{
    srand(INF);     //������� 
    tim=1;
    node->flag=1;
    node->son[0]=node->son[1]=node;     //null�����Ҷ���ָ��null 
    now_node=root=null=node;
}

Tree newNode(int key)   //�����½ڵ� 
{
    //++sum_peo;
    ++now_node;
    now_node->key=key;
    now_node->key_cnt=1;
    now_node->heap_key=rand();
    now_node->size=1;
    now_node->flag=0;
    now_node->son[0]=now_node->son[1]=null;
    now_node->tim=tim;
    return now_node;
}

void rotate(Tree &root,bool flag)   //��ת��flag==0��������==1������ 
{
    Tree tmp=root->son[!flag];
    root->son[!flag]=tmp->son[flag];
    tmp->son[flag]=root;
    root->size=root->son[0]->size+root->son[1]->size+root->key_cnt;
    tmp->size=tmp->son[0]->size+tmp->son[1]->size+tmp->key_cnt;
    root=tmp;
}

void insert(Tree &root,int key)
{
    if(root==null)      //���µĹ��ʵ��� 
        root=newNode(key);
    else if(key==root->key)     //��ͬ��������++ 
    {
        ++root->key_cnt,++root->size;
    }
    else
    {
        bool flag=key<root->key;
        insert(root->son[flag],key);
        ++root->size;
        if(root->heap_key<root->son[flag]->heap_key)
            rotate(root,!flag);
    }
}

void erase(Tree &root,int key,int num)      //num��Ա������ 
{
    if(root==null)
        return;
    if(key!=root->key)
    {
        bool flag=key<root->key;
        erase(root->son[flag],key,num);
        root->size-=num;
    }
    else
    {
        if(root->son[0]==null)
        {
            //change=root;
            //printf("A:  change:%d  root:%d\n",change,root);
            root=root->son[1];
            //printf("B:  change:%d  root:%d\n",change,root);
        }
        else if(root->son[1]==null)
        {
            //change=root;
            root=root->son[0];
        }
        else
        {
            bool flag=root->son[0]->heap_key>root->son[1]->heap_key;
            rotate(root,flag);
            erase(root->son[flag],key,num);
            root->size-=num;
        }
    }
}

int query_num(Tree root,int k)      //ѯ�ʵ�k�� 
{
    if(root==null)
        return 0;
    if(k<=root->son[0]->size)
        return query_num(root->son[0],k);
    if(k>root->son[0]->size+root->key_cnt)
        return query_num(root->son[1],k-root->son[0]->size-root->key_cnt);
    return root->key;
}
//
//Tree find(Tree x)
//{
//  return x->fa==x?x:x->fa=find(x->fa);
//}

int main()
{
    //freopen("233.in","r",stdin);
    //freopen("233.out","w",stdout);
    init();     //�������ó�ʼ������ 
    n=read(),minn=read();
    while(n--)
    {
        opt=read(),x=read();
        switch(opt)
        {
            case 1:
                if(x>=minn)
                    ++sum_peo,      //��ְԱ������++ 
                    insert(root,x);
                break;
            case 2:
                for(Tree i=node+1;i<=now_node;++i)
                {
                    if(i->flag==1)  //������ 
                        continue;
                    i->key+=x;      //�ǹ��� 
                }
                break;
            case 3:
                //printf("be:  %d\n",sum_peo);
                for(Tree i=node+1;i<=now_node;++i)
                {
                    if(i->flag==1)      //�Ѿ������� 
                        continue;
                    i->key-=x;  //�۹��� 
                    if(i->key<minn)
                    {
                        //Tree change=null;
                        //printf("C: change: %d\n",change);
                        erase(root,i->key,i->key_cnt);
                        sum_peo-=i->key_cnt;    //��ȥ������ʵ����� 
                        leave_peo+=i->key_cnt;  //�������� 
                        i->flag=1;  //���һ���Ѿ����� 
                        //printf("D: change: %d\n",change);
                        //change=null;
                        //printf("E: change: %d\n",change);
                    }
                }
                //printf("af:  %d\n",sum_peo);
                break;
            default:
                //printf("peo: %d\n",sum_peo);
                if(x>sum_peo)
                    printf("-1\n");
                else printf("%d\n",query_num(root,x));
        }
    }
    printf("%d",leave_peo);
    return 0;
}
