#include<cstdio>
#include<cstring>
int main()
{
    double A[3][3]={{3,-1,1},{3,6,2},{3,3,7}};
    printf("Jacobi迭代法");
    printf("A矩阵：\n");
    for(int k=0;k<3;k++)
        for(int j=0;j<3;j++)
            {
                printf("%.4lf  ",A[k][j]);
                if(j==2)
                    printf("\n");
            }
    printf("\n");
    double GJ[3][3];
    memset(GJ,0,sizeof(GJ));
    for(int k=0;k<3;k++)
        for(int j=0;j<3;j++)
            {
                if(k==j)
                    continue;
                GJ[k][j]=-1*(A[k][j]/A[k][k]);
            }
    printf("迭代矩阵GJ：\n");
    for(int k=0;k<3;k++)
        for(int j=0;j<3;j++)
            {
                printf("%.4lf  ",GJ[k][j]);
                if(j==2)
                    printf("\n");
            }
    printf("\n");
    double x1,x2,x3;
    x1=0.0;
    x2=0.0;
    x3=0.0;
    double temp1,temp2,temp3;
    temp1=0.0;
    temp2=0.0;
    temp3=0.0;
    printf("Jacobi迭代法\n");
    for(int i=0;i<2;i++)
        {
            temp1=GJ[0][1]*x2+GJ[0][2]*x3+1.0/3.0;
            temp2=GJ[1][0]*x1+GJ[1][2]*x3+0.0;
            temp3=GJ[2][0]*x1+GJ[2][1]*x2+4.0/7.0;
            x1=temp1;
            x2=temp2;
            x3=temp3;
            printf("第%d次迭代结果x(%d)：%lf %lf %lf\n",i+1,i+1,x1,x2,x3);
        }
    printf("\n");
    double y1,y2,y3;
    y1=0.0;
    y2=0.0;
    y3=0.0;
    printf("Gauss-Seidel迭代法\n");
    for(int i=0;i<2;i++)
        {
            y1=GJ[0][1]*y2+GJ[0][2]*y3+1.0/3.0;
            y2=GJ[1][0]*y1+GJ[1][2]*y3+0.0;
            y3=GJ[2][0]*y1+GJ[2][1]*y2+4.0/7.0;
            printf("第%d次迭代结果x(%d)：%lf %lf %lf\n",i+1,i+1,y1,y2,y3);
        }
    return 0;
}
