#include<stdio.h>
int main()
{
    int i,k[1000],n;
    printf("Enter the value of n = ");
    scanf("%d",&n);
     for(i=1;i<=n;i++)
        scanf("%d",&k[i]);
        printf("The inserted values are \n");
    for(i=1;i<=n;i++)
    if(i%2!=0)
        printf("index[%d]=%d\n",i,k[i]);

        return 0;
}


