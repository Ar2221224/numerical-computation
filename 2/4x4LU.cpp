#include<cstdio>
#include<cmath>
//该代码为LU分解法解法，用于验证答案准确性
PrintMatrix(double A[4][4])
{
    int i,j;
    for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
                printf("%.4f   ",A[i-1][j-1]);
            printf("\n");
        }
}
double FindMax(double a[4])
{
    int i;
    double x=fabs(a[0]);
    for(i=2;i<=4;i++)
        if(fabs(a[i-1])>=x)
            x=fabs(a[i-1]);
    return (x);
}
Factorization(double A[4][4],int p[4])
{
    int i,k,j,m;
    double s[4];
    double z;
    for(i=1;i<=4;i++)
        {
            p[i-1]=i;
            s[i-1]=FindMax(A[i-1]);
        }
    for(k=1;k<=3;k++)
        {
            for(i=k;i<=4;i++)
                {
                    j=k;
                    if(fabs(A[p[j-1]-1][k-1])/s[p[j-1]-1]<=fabs(A[p[i-1]-1][k-1])/s[p[i-1]-1])
                        j=i;
                }
                m=p[k-1];
                p[k-1]=p[j-1];
                p[j-1]=m;
                for(i=k+1;i<=4;i++)
                    {
                        z=A[p[i-1]-1][k-1]/A[p[k-1]-1][k-1];
                        A[p[i-1]-1][k-1]=z;
                        for(j=k+1;j<=4;j++)
                            A[p[i-1]-1][j-1]=A[p[i-1]-1][j-1]-z*A[p[k-1]-1][j-1];
                    }
        }
}
Solving(double A[4][4],int p[4],double b[4],double x[4])
{
    int i,k,j;
    double sum;
    for(k=1;k<=3;k++)
        for(i=k+1;i<=4;i++)
            b[p[i-1]-1]=b[p[i-1]-1]-A[p[i-1]-1][k-1]*b[p[k-1]-1];
    for(i=4;i>=1;i--)
        {
            sum=0;
            for(j=i+1;j<=4;j++)
                sum=sum+(A[p[i-1]-1][j-1]*x[j-1]);
            x[i-1]=(b[p[i-1]-1]-sum)/A[p[i-1]-1][i-1];
        }
}
FindL(double A[4][4],double L[4][4],int p[4])
{
    int i,j;
    for(i=1;i<=4;i++)
        for(j=1;j<=4;j++)
            L[i-1][j-1]=0;
    for(i=1;i<=4;i++)
        L[i-1][i-1]=1;
    for(i=1;i<=3;i++)
        for(j=1;j<=i;j++)
            L[i][j-1]=A[p[i]-1][j-1];
}
FindU(double A[4][4],double U[4][4],int p[4])
{
    int i,j;
    for(i=1;i<=4;i++)
        for(j=1;j<=4;j++)
            U[i-1][j-1]=0;
    for(i=1;i<=4;i++)
        for(j=i;j<=4;j++)
            U[i-1][j-1]=A[p[i-1]-1][j-1];
}
FindP(double P[4][4],int p[4])
{
    int i,j;
    for(i=1;i<=4;i++)
        for(j=1;j<=4;j++)
            P[i-1][j-1]=0;
    for(i=1;i<=4;i++)
        P[i-1][4-i]=1;
}
int main()
{
    double A[4][4]={{1,2,3,4},{1,4,9,16},{1,8,27,64},{1,16,81,256}};
    double B[4][4];
    double P[4][4],L[4][4],U[4][4];
    int i,j,p[4];
    double x[4];
    double b[4]={2,10,44,190};
    for(i=1;i<=4;i++)
        for(j=1;j<=4;j++)
            B[i-1][j-1]=A[i-1][j-1];
    printf("Matrix A is:\n");
    PrintMatrix(B);
    printf("\n");
    Factorization(B,p);
    FindP(P,p);
    FindL(B,L,p);
    FindU(B,U,p);
    printf("Matrix P is:\n");
    PrintMatrix(P);
    printf("\n");
    printf("Matrix L is:\n");
    PrintMatrix(L);
    printf("\n");
    printf("Matrix U is:\n");
    PrintMatrix(U);
    printf("\n");
    Solving(B,p,b,x);
    printf("The roots are:\n");
    for(i=1;i<=4;i++)
        printf("%f   ",x[i-1]);
    printf("\n");
    return 0;
}
