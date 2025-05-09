#include<stdio.h>
int main()
{
    int i,k[5];
     for(i=1;i<=5;i++)
        scanf("%d",&k[i]);
    for(i=1;i<=5;i++)
    if(i%2!=0)
        printf("%d\n",k[i]);

        return 0;
}

