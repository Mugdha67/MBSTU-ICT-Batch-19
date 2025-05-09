#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,i,count=0;
        scanf("%d",&N);
        for(i=5;i<=N;i*=5)
        {
            count=count+(N/i);
        }
        printf("%d\n",count);
    }
    return 0;
}
