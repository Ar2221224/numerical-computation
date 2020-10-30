#include<cstdio>
#include<cstring>
int main()
{
    double A[4][4]={{2,1,0,0},{1,3,1,0},{0,1,1,1},{0,0,2,1}};
    printf("A矩阵：\n");
    for(int k=0;k<4;k++)
        for(int j=0;j<4;j++)
            {
                printf("%.1lf  ",A[k][j]);
                if(j==3)
                    printf("\n");
            }
    printf("\n");
    double L[4][4],U[4][4];
    memset(L,0,sizeof(L));
    memset(U,0,sizeof(U));
    for(int i=0;i<4;i++)
        L[i][i]=1;
    L[1][0]=A[1][0]/A[0][0];
    for(int k=2;k<4;k++)
        for(int j=k-1;j<k;j++)
            L[k][j]=A[k][j]/(A[j][j]-L[k-1][j-1]*A[j-1][k-1]);
    /*  此处完整算法
        L[2][1]=A[2][1]/(A[1][1]-L[1][0]*A[0][1]);
        L[3][2]=A[3][2]/(A[2][2]-L[2][1]*A[1][2]);
    */
    printf("L矩阵：\n");
    for(int k=0;k<4;k++)
        for(int j=0;j<4;j++)
            {
                printf("%.1lf  ",L[k][j]);
                if(j==3)
                    printf("\n");
            }
    printf("\n");
    U[0][1]=A[0][1];
    U[1][2]=A[1][2];
    U[2][3]=A[2][3];
    U[0][0]=A[0][0];
    for(int k=1;k<4;k++)
        U[k][k]=A[k][k]-L[k][k-1]*U[k-1][k];
    /*  此处完整算法
        U[1][1]=A[1][1]-L[1][0]*U[0][1];
        U[2][2]=A[2][2]-L[2][1]*U[1][2];
        U[3][3]=A[3][3]-L[3][2]*U[2][3];
    */
    printf("U矩阵：\n");
    for(int k=0;k<4;k++)
        for(int j=0;j<4;j++)
            {
                printf("%.1lf  ",U[k][j]);
                if(j==3)
                    printf("\n");
            }
    printf("\n");
    //以上为求LU矩阵的过程
    double ans[4][1]={{3},{5},{3},{3}};
    double y[4][1];
    y[0][0]=ans[0][0]/L[0][0];
    for(int k=1;k<4;k++)
        y[k][0]=ans[k][0]-L[k][k-1]*y[k-1][0];
    /*  此处完整算法
        y[1][0]=ans[1][0]-L[1][0]*y[0][0];
        y[2][0]=ans[2][0]-L[2][1]*y[1][0];
        y[3][0]=ans[3][0]-L[3][2]*y[2][0];
    */
    printf("y矩阵：\n");
    for(int k=0;k<4;k++)
        printf("%.1lf  \n",y[k][0]);
    printf("\n");
    double x[4][1];
    x[3][0]=y[3][0]/U[3][3];
    for(int k=2;k>=0;k--)
        x[k][0]=(y[k][0]-x[k+1][0])/U[k][k];
    /*  此处完整算法
        x[2][0]=(y[2][0]-x[3][0])/U[2][2];
        x[1][0]=(y[1][0]-x[2][0])/U[1][1];
        x[0][0]=(y[0][0]-x[1][0])/U[0][0];
    */
    printf("X矩阵：\n");
    for(int k=0;k<4;k++)
        printf("%.1lf  \n",x[k][0]);
    printf("\n");
    return 0;
}
