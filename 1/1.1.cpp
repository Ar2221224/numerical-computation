#include<cstdio>
int main()
{
    int y,y1,x;
    for(x=0;x<=10;x++)
        {
            y=x*x*x-2*x-5;
            if(y>=0) break;
        }
    y1=(x-1)*(x-1)*(x-1)-2*(x-1)-5;
    printf("������ɨ���f(%d)=%d,f(%d)=%d,�����̵��и�����Ϊ[%d,%d]\n",x-1,y1,x,y,x-1,x);
    //������
    int y2=3*x*x-2;
    int y3=3*(x-1)*(x-1)-2;
    if(y2>0&&y3>0)
        printf("f(x)��[%d,%d]��Ψһ��\n",x-1,x);
    else
        printf("f(x)��[%d,%d]�и���Ψһ\n",x-1,x);
    //�жϸ��Ƿ�Ψһ
    double ak,bk,xk;
    ak=x-1,bk=x,xk=(ak+bk)/2;
    printf("��������          ak           bk           xk\n");
    for(int times=0;bk-ak>=1e-3;times++)
        {
            printf("    %d          %lf     %lf     %lf\n",times,ak,bk,xk);
            if(xk*xk*xk-2*xk-5>0)
                bk=xk;
            else ak=xk;
            xk=(ak+bk)/2;
        }
    //���ַ�
    return 0;
}
