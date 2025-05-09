#include<stdio.h>
int main()
{
    int T,N,i,sum=0;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&N);
        sum=(N/10000)+(N%10);
        printf("Sum = %d\n",sum);
    }
    return 0;
}
