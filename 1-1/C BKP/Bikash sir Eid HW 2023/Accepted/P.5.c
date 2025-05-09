#include<stdio.h>
int main()
{
    int T,t,n,i,j;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("*",j);
            }
            printf("\n",i);
        }
        printf("\n",t);
    }
    return 0;
}
