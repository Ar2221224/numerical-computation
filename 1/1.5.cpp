#include<cstdio>
double F(double n,double m,int k)
{
    printf("%d          %.10lf          %.10lf\n",k,n,n*n*n-2*n-5);
}
int main()
{
    double n=2.0;
    double m=3.0;
    printf("k              xn                    f(xn)\n");
    for(int k=0;k<=9;k++)
        {
            if(k==0)
                F(n,m,k);
            else
                {
                    double a=m;
                    m=m-(m-n)/(m*m*m-2*m-5-(n*n*n-2*n-5))*(m*m*m-2*m-5);
                    n=a;
                    F(n,m,k);
                }
        }
    return 0;
}
