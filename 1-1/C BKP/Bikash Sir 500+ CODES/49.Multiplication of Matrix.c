#include<stdio.h>
int main()
{
    int a[4][4],b[4][4],m[4][4],sum,i,j,k;
    for(i=1;i<=3;i++)
        {
            for(j=1;j<=3;j++)
            {
               scanf("%d",&a[i][j]);
            }
        }

        for(i=1;i<=3;i++)
        {
            for(j=1;j<=3;j++)
            {
               scanf("%d",&b[i][j]);
            }
        }

        for(i=1;i<=3;i++)
        {
            for(j=1;j<=3;j++)
            {
            m[i][j]=0,sum=0;
               for(k=1;k<=3;k++)
            {
               sum=sum+a[i][k]*b[k][j];
               m[i][j]=sum;
            }
            }
        }
        for(i=1;i<=3;i++)
        {
            for(j=1;j<=3;j++)
            {

               printf("%d ",m[i][j]);


            }
            printf("\n");
        }
    return 0;
}
