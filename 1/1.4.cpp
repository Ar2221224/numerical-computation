#include<cstdio>
int main()
{
    printf("µü´ú´ÎÊý      xk\n");
    double x,y,y1;
    x=1.0;
    for(int k=0;k<=12;k++)
        {
            printf("%d          %.10lf\n",k,x);
            y=x*x-6.0;
            y1=2.0*x;
            x=x-y/y1;
        }
    return 0;
}
