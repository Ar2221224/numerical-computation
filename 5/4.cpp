#include<cstdio>
int main()
{
    double h=0.2;
    double y[10],x[10];
    y[0]=1.0,x[0]=0.0;
    printf("代码计算无保留两位小数\n");
    for(int i=1;i<=6;i++)
        {
            y[i]=y[i-1]+0.5*h*h*((h+2)*(x[i-1]+y[i-1])+h);
            printf("y(%d)=%lf\n",i,y[i]);
            x[i+1]=x[i]+h;
        }
    return 0;
}
