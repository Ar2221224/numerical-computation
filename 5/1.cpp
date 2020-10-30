#include<cstdio>
#include<math.h>
int main()
{
    double stdf=(-2.0)/((1+1.1)*(1+1.1)*(1+1.1));
    double f1=(1.0/((1+1.1)*(1+1.1))-1.0/((1+1.0)*(1+1.0)))/(1.1-1.0);
    double f2=(1.0/((1+1.2)*(1+1.2))-1.0/((1+1.1)*(1+1.1)))/(1.2-1.1);
    double f3=(1.0/((1+1.2)*(1+1.2))-1.0/((1+1.0)*(1+1.0)))/(1.2-1.0);
    double error1=fabs(stdf-f1);
    double error2=fabs(stdf-f2);
    double error3=fabs(stdf-f3);
    printf("f`(1.1)=%lf\n",stdf);
    printf("����΢�ֹ�ʽ1.1 1.0��f`(1.1)=%lf,���Ϊ%lf\n",f1,error1);
    printf("����΢�ֹ�ʽ1.2 1.1��f`(1.1)=%lf,���Ϊ%lf\n",f2,error2);
    printf("����΢�ֹ�ʽ1.2 1.0��f`(1.2)=%lf,���Ϊ%lf\n",f3,error3);
    return 0;
}
