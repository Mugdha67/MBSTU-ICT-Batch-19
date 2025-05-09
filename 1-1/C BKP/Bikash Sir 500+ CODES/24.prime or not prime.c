// prime or not prime??
#include<stdio.h>
int main()
{
    int n,i,flag=1;
    scanf("%d",&n);
    for(i=2;i<=n/2;i++)
        if(n%i==0)
    {
        flag=0;
    break;
    }
    if(flag==1)
        printf("Prime\n");
        else
        printf("Not Prime\n");
    return 0;
}

