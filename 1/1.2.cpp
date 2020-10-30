#include<cstdio>
#include<cmath>
int main()
{
    printf("k      xk\n");
    double xk=1.5;
    for(int k=0;k<=15;k++)
        {
            printf("%d    %lf\n",k,xk);
            xk=pow(xk+1,1.0/3);
        }
    return 0;
}
