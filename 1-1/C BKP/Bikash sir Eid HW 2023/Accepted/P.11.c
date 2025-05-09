#include<stdio.h>
int main()
{
    int T,N;
    scanf("%d",&T);
    while(T--)
    {
        long long int F=1,i;
        scanf("%d",&N);
        for(i=1;i<=N;i++)
        {
            F=F*i;
        }
        printf("%lld\n",F);
    }
    return 0;
}
