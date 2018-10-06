#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN = 1e6 + 10;
using namespace std;
char s[MAXN];
int N, M, rak[MAXN], sa[MAXN], tax[MAXN], tp[MAXN];
void Debug() {
    printf("*****************\n");
    printf("�±�"); for(int i = 1; i <= N; i++) printf("%d ", i);     printf("\n");
    printf("sa  "); for(int i = 1; i <= N; i++) printf("%d ", sa[i]); printf("\n");
    printf("rak "); for(int i = 1; i <= N; i++) printf("%d ", rak[i]);printf("\n");
    printf("tp  "); for(int i = 1; i <= N; i++) printf("%d ", tp[i]); printf("\n");
}
void Qsort() {
    for(int i = 0; i <= M; i++) tax[i] = 0;
    for(int i = 1; i <= N; i++) tax[rak[i]]++;
    for(int i = 1; i <= M; i++) tax[i] += tax[i - 1];
    for(int i = N; i >= 1; i--) sa[ tax[rak[tp[i]]]-- ] = tp[i];
    //�ⲿ���ҵ����µ�ĩβ��ϸ��˵���� 
}
void SuffixSort() {
    M = 75;
    for(int i = 1; i <= N; i++) rak[i] = s[i] - '0', tp[i] = i;
    Qsort();
    Debug();
    for(int w = 1, p = 0; p < N; M = p, w <<= 1) {
        //w:��ǰ�����ĳ��ȣ�w = x��ʾ�Ѿ�����˳���Ϊx�ĺ�׺������������Ҫ���³���Ϊ2x�ĺ�׺������
        //p��ʾ��ͬ�ĺ�׺�ĸ���������Ȼԭ�ַ����ĺ�׺���ǲ�ͬ�ģ����p = Nʱ�����˳�ѭ�� 
        p = 0;//�����p������һ�������� 
        for(int i = 1; i <= w; i++) tp[++p] = N - w + i;
        for(int i = 1; i <= N; i++) if(sa[i] > w) tp[++p] = sa[i] - w;//�������Ǻ�׺����ĺ��Ĳ��֣����Ѿ���ͼ˵�� 
        for (int i = 1; i <= p; i++) 
        	printf("%d ", tp[i]); puts("");
        Qsort();//��ʱ�����Ѿ����³��˵ڶ��ؼ��֣�������һ�ֵ�rak���±��ֵ�sa 
        std::swap(tp, rak);//����ԭ��tp�Ѿ�û������ 
        rak[sa[1]] = p = 1;
        for(int i = 2; i <= N; i++)
            rak[sa[i]] = (tp[sa[i - 1]] == tp[sa[i]] && tp[sa[i - 1] + w] == tp[sa[i] + w]) ? p : ++p;
        //���ﵱ������׺��һ��������ͬʱ����Ҳ��ͬ������Ϊʲô��ҿ���˼��һ�� 
        Debug();
    }
    for(int i = 1; i <= N; i++)
        printf("%d ", sa[i]);
}
int main() {
	freopen("INPUT", "r", stdin);
    scanf("%s", s + 1);
    N = strlen(s + 1);
    SuffixSort();
    return 0;
}
