#include<stdio.h>
int main()
{
    int n,r,x=0;
    scanf("%d",&n);
    while(n>0){
    r=n%10;
    n=n/10;
    x=x*10+r;
    }
    printf("%d",x);
    return 0;
}
