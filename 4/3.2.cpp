#include<cstdio>
int main()
{
    printf("xi           f[xi]     1╫в╡Нил    2╫в╡Нил   3╫в╡Нил\n");
    double x0=0.0,x1=2.0,x2=3.0,x3=5.0;
    double fx0=1.0,fx1=3.0,fx2=2.0,fx3=5.0;
    printf("%lf   %lf\n",x0,fx0);
    printf("%lf   %lf   %lf\n",x1,fx1,(fx1-fx0)/(x1-x0));
    printf("%lf   %lf   %lf   %lf\n",x2,fx2,(fx2-fx1)/(x2-x1),((fx2-fx1)/(x2-x1)-(fx1-fx0)/(x1-x0))/(x2-x0));
    double a=((fx2-fx1)/(x2-x1)-(fx1-fx0)/(x1-x0))/(x2-x0);
    double b=((fx3-fx2)/(x3-x2)-(fx2-fx1)/(x2-x1))/(x3-x1);
    printf("%lf   %lf   %lf   %lf   %lf\n",x3,fx3,(fx3-fx2)/(x3-x2),((fx3-fx2)/(x3-x2)-(fx2-fx1)/(x2-x1))/(x3-x1),(b-a)/(x3-x0));
    return 0;
}
