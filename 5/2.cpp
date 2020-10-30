#include<cstdio>
int main()
{
    double h=0.2;
    double y[10],x[10];
    y[0]=1.0,x[0]=0.0;
    for(int i=1;i<=4;i++)
        {
            y[i]=0.8*y[i-1]-0.2*x[i-1]*y[i-1]*y[i-1];
            printf("y(%d)=%lf\n",i,y[i]);
            x[i]=x[i-1]+0.2;
        }
    return 0;
}
