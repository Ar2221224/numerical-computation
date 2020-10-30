#include<cstdio>
int main()
{
    double h=0.1;
    double y[10],x[10];
    y[0]=1.0,x[0]=0.0,x[1]=0.1;
    for(int i=1;i<=2;i++)
        {
            y[i]=0.5*(h*(1+h)*x[i-1]+h*x[i])+(1+h+h*h/2)*y[i-1];
            printf("y(%d)=%lf\n",i,y[i]);
            x[i+1]=x[i]+h;
        }
    return 0;
}
