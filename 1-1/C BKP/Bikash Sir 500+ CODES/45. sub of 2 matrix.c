#include<stdio.h>
int main()
{
    int a[10][10],b[10][10],i,j,sub[10][10];
    for(i=1;i<=3;i++){
        for(j=1;j<=3;j++)
        scanf("%d",&a[i][j]);
    }

    for(i=1;i<=3;i++){
        for(j=1;j<=3;j++)
        scanf("%d",&b[i][j]);
    }

    for(i=1;i<=3;i++){
        for(j=1;j<=3;j++){
        sub[i][j]=a[i][j]-b[i][j];
        printf("%d  ",sub[i][j]);

        }
         printf("\n");
    }


    return 0;
}
