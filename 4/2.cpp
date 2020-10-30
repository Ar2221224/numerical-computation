#include<cstdio>
int main()
{
    double x0=0.0,x1=2.0,x2=3.0,x3=5.0,y0=1.0,y1=3.0,y2=2.0,y3=5.0;
    double x[4],a[4][4]={{1,-10,31,-30}};//这一步暂时没想到比较好的计算方法
    double deno1,deno2,deno3,deno4;
    deno1=(x0-x1)*(x0-x2)*(x0-x3)/y0;
    deno2=(x1-x0)*(x1-x2)*(x1-x3)/y1;
    deno3=(x2-x0)*(x2-x1)*(x2-x3)/y2;
    deno4=(x3-x0)*(x3-x1)*(x3-x2)/y3;
    for(int i=1;i<4;i++)
        {
            a[i][0]=1;
            a[i][3]=0;
        }
    a[1][1]=-1*(x2+x3);
    a[1][2]=x2*x3;
    a[2][1]=-1*(x1+x3);
    a[2][2]=x1*x3;
    a[3][1]=-1*(x1+x2);
    a[3][2]=x1*x2;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            {
                if(i==0) a[i][j]/=deno1;
                if(i==1) a[i][j]/=deno2;
                if(i==2) a[i][j]/=deno3;
                if(i==3) a[i][j]/=deno4;
            }
    x[0]=a[0][0]+a[1][0]+a[2][0]+a[3][0];
    x[1]=a[0][1]+a[1][1]+a[2][1]+a[3][1];
    x[2]=a[0][2]+a[1][2]+a[2][2]+a[3][2];
    x[3]=a[0][3]+a[1][3]+a[2][3]+a[3][3];
    printf("L3=%.3lfx3%.3lfx2+%.3lfx+%.0lf\n",x[0],x[1],x[2],x[3]);
    return 0;
}

