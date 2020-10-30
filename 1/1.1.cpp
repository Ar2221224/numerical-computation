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
    printf("搜索法扫描得f(%d)=%d,f(%d)=%d,即方程的有根区间为[%d,%d]\n",x-1,y1,x,y,x-1,x);
    //搜索法
    int y2=3*x*x-2;
    int y3=3*(x-1)*(x-1)-2;
    if(y2>0&&y3>0)
        printf("f(x)在[%d,%d]有唯一根\n",x-1,x);
    else
        printf("f(x)在[%d,%d]有根不唯一\n",x-1,x);
    //判断根是否唯一
    double ak,bk,xk;
    ak=x-1,bk=x,xk=(ak+bk)/2;
    printf("迭代次数          ak           bk           xk\n");
    for(int times=0;bk-ak>=1e-3;times++)
        {
            printf("    %d          %lf     %lf     %lf\n",times,ak,bk,xk);
            if(xk*xk*xk-2*xk-5>0)
                bk=xk;
            else ak=xk;
            xk=(ak+bk)/2;
        }
    //二分法
    return 0;
}
