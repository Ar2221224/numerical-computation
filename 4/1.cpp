#include<cstdio>
int main()
{
    double x0=2.0,y0=0.6931,x1=2.2,y1=0.7885,x2=2.3,y2=0.8329,x=2.1;
    double L1,L2;
    L1=(x-x1)/(x0-x1)*y0+(x-x0)/(x1-x0)*y1;
    //���Բ�ֵ
    L2=(x-x1)*(x-x2)/((x0-x1)*(x0-x2))*y0+(x-x0)*(x-x2)/((x1-x0)*(x1-x2))*y1+(x-x0)*(x-x1)/((x2-x0)*(x2-x1))*y2;
    //�����ֵ
    printf("L1=%lf\nL2=%lf\n",L1,L2);
    return 0;
}
