# include <bits/stdc++.h>
using namespace std;
const int MAXN=105;
      double eps=0.000001; //�����Ƽ�1e-4��1e-10֮��
double a[MAXN][MAXN],val[MAXN];
int n;
void swapline(int i)//����i�к�������У���֤i�м���������
{
    int j=i+1;
    while (fabs(a[j][i]) < eps && j<=n) ++j;
    if (j>n) {
        printf("No Solution\n");
        return;
    }
    if (j<=n) {swap(a[i],a[j]);swap(val[i],val[j]);}
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)  {
        for (int j=1;j<=n;j++) scanf("%lf",&a[i][j]);
        scanf("%lf",&val[i]);
    }
    for (int i=1;i<=n-1;i++) {
        double num=a[i][i];
        if (fabs(num)<eps)  swapline(i);
        for (int j=i+1;j<=n;j++) {
            if (fabs(a[j][i])<=eps) continue;//��������Ԫa[i][i]=0ʱ������
            double w=-a[j][i]/num; a[j][i]=0;
            for (int k=i+1;k<=n;k++) a[j][k]+=a[i][k]*w;
            val[j]+=val[i]*w;
        }
    }//�������Ǿ���
    for (int i=1;i<=n;i++) {
        bool flag=true;
        for (int j=1;j<=n;j++)
         if (fabs(a[i][j])>eps) {
            flag=false;break;
         }
        if (flag) {
            printf("No Solution\n");
            return 0; //�ж��Ƿ��޽���ж����
        }
    }
    val[n]=val[n]/a[n][n];//�����n��Ԫ
    for (int i=n-1;i>=1;i--) {
        double sum=0;
        for (int j=n;j>=i+1;j--) sum=sum+a[i][j]*val[j];
        val[i]=(val[i]-sum)/a[i][i];
    }//������֪Ԫ���δ֪��һ��Ԫ
    for (int i=1;i<=n;i++) printf("%.2lf\n",val[i]);
    return 0;
}
