#include<stdio.h>
#include<math.h>
int main()
{
    int T,i,N,n;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&N);
        n=sqrt(N);
        if(n*n==N)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
