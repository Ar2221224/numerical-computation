#include<cstdio>
#include<cmath>
//该代码为LU分解法解法，用于验证答案准确性
PrintMatrix(double A[3][3])
{
    int i,j;
    for(i=1;i<=3;i++)
        {
            for(j=1;j<=3;j++)
                printf("%.4f   ",A[i-1][j-1]);
            printf("\n");
        }
}
double FindMax(double a[3])
{
    int i;
    double x=fabs(a[0]);
    for(i=2;i<=3;i++)
        if(fabs(a[i-1])>=x)
            x=fabs(a[i-1]);
    return (x);
}
Factorization(double A[3][3],int p[3])
{
    int i,k,j,m;
    double s[3];
    double z;
    for(i=1;i<=3;i++)
        {
            p[i-1]=i;
            s[i-1]=FindMax(A[i-1]);
        }
    for(k=1;k<=2;k++)
        {
            for(i=k;i<=3;i++)
                {
                    j=k;
                    if(fabs(A[p[j-1]-1][k-1])/s[p[j-1]-1]<=fabs(A[p[i-1]-1][k-1])/s[p[i-1]-1])
                        j=i;
                }
                m=p[k-1];
                p[k-1]=p[j-1];
                p[j-1]=m;
                for(i=k+1;i<=3;i++)
                    {
                        z=A[p[i-1]-1][k-1]/A[p[k-1]-1][k-1];
                        A[p[i-1]-1][k-1]=z;
                        for(j=k+1;j<=3;j++)
                            A[p[i-1]-1][j-1]=A[p[i-1]-1][j-1]-z*A[p[k-1]-1][j-1];
                    }
        }
}
Solving(double A[3][3],int p[3],double b[3],double x[3])
{
    int i,k,j;
    double sum;
    for(k=1;k<=2;k++)
        for(i=k+1;i<=3;i++)
            b[p[i-1]-1]=b[p[i-1]-1]-A[p[i-1]-1][k-1]*b[p[k-1]-1];
    for(i=3;i>=1;i--)
        {
            sum=0;
            for(j=i+1;j<=3;j++)
                sum=sum+(A[p[i-1]-1][j-1]*x[j-1]);
            x[i-1]=(b[p[i-1]-1]-sum)/A[p[i-1]-1][i-1];
        }
}
FindL(double A[3][3],double L[3][3],int p[3])
{
    int i,j;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            L[i-1][j-1]=0;
    for(i=1;i<=3;i++)
        L[i-1][i-1]=1;
    for(i=1;i<=2;i++)
        for(j=1;j<=i;j++)
            L[i][j-1]=A[p[i]-1][j-1];
}
FindU(double A[3][3],double U[3][3],int p[3])
{
    int i,j;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            U[i-1][j-1]=0;
    for(i=1;i<=3;i++)
        for(j=i;j<=3;j++)
            U[i-1][j-1]=A[p[i-1]-1][j-1];
}
FindP(double P[3][3],int p[3])
{
    int i,j;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            P[i-1][j-1]=0;
    for(i=1;i<=3;i++)
        P[i-1][p[i-1]-1]=1;
}
int main()
{
    double A[3][3]={{0.2641,0.1735,0.8642},{0.9411,-0.0175,0.1463},{-0.8641,-0.4243,0.0711}};
    double B[3][3];
    double P[3][3],L[3][3],U[3][3];
    int i,j,p[3];
    double x[3];
    double b[3]={-0.7521,0.6310,0.2500};
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
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
    for(i=1;i<=3;i++)
        printf("%f   ",x[i-1]);
    printf("\n");
    return 0;
}
