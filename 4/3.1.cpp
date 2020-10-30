#include<cstdio>
int main()
{
    printf("xi           f[xi]     1╫в╡Нил    2╫в╡Нил\n");
    double x0=2.0,x1=2.2,x2=2.3;
    double fx0=0.6931,fx1=0.7885,fx2=0.8329;
    printf("%lf   %lf\n",x0,fx0);
    printf("%lf   %lf   %lf\n",x1,fx1,(fx1-fx0)/(x1-x0));
    printf("%lf   %lf   %lf   %lf\n",x2,fx2,(fx2-fx1)/(x2-x1),((fx2-fx1)/(x2-x1)-(fx1-fx0)/(x1-x0))/(x2-x0));
    return 0;
}
