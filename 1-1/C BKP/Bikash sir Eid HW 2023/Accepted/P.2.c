#include<stdio.h>
int main()
{
    int T,i,l=0,N;
    char n [101];
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%s",&n);
        l=strlen(n);
        N=l-1;
        if(n[N]%2==0)
        {
            printf("even\n");
        }
        else
        {
            printf("odd\n");
        }
    }
    return 0;
}
