#include<stdio.h>
int main()
{
    long long int n,i,a=1;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        a=a*i;
    printf("%lld",a);
    return 0;
}
//factorial
