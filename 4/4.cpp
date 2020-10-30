#include<cstdio>
int main()
{
    printf("xi           f[xi]     1╫в╡Нил    2╫в╡Нил    3╫в╡Нил    4╫в╡Нил    5╫в╡Нил\n");
    double x0=0.40,x1=0.55,x2=0.65,x3=0.80,x4=0.90,x5=1.05;
    double fx0=0.41075,fx1=0.57815,fx2=0.69675,fx3=0.88811,fx4=1.02652,fx5=1.25382;
    printf("%lf   %lf\n",x0,fx0);
    double a=(fx1-fx0)/(x1-x0);
    printf("%lf   %lf   %lf\n",x1,fx1,a);
    double b=(fx2-fx1)/(x2-x1);
    double c=((fx2-fx1)/(x2-x1)-(fx1-fx0)/(x1-x0))/(x2-x0);
    printf("%lf   %lf   %lf   %lf\n",x2,fx2,b,c);
    double d=(fx3-fx2)/(x3-x2);
    double e=((fx3-fx2)/(x3-x2)-(fx2-fx1)/(x2-x1))/(x3-x1);
    double f=(e-c)/(x3-x0);
    printf("%lf   %lf   %lf   %lf   %lf\n",x3,fx3,d,e,f);
    double g=(fx4-fx3)/(x4-x3);
    double h=((fx4-fx3)/(x4-x3)-(fx3-fx2)/(x3-x2))/(x4-x2);
    double i=(h-e)/(x4-x1);
    double j=(i-f)/(x4-x0);
    printf("%lf   %lf   %lf   %lf   %lf   %lf\n",x4,fx4,g,h,i,j);
    double k=(fx5-fx4)/(x5-x4);
    double l=((fx5-fx4)/(x5-x4)-(fx4-fx3)/(x4-x3))/(x5-x3);
    double m=(l-h)/(x5-x2);
    double n=(m-i)/(x5-x1);
    double o=(n-j)/(x5-x0);
    printf("%lf   %lf   %lf   %lf   %lf   %lf   %lf\n",x5,fx5,k,l,m,n,o);
    return 0;
}
