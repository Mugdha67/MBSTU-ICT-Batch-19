#include<stdio.h>
#include<math.h>
int main()
{
    int n,k,x;
    scanf("%d",&n);
    x=sqrt(n);
    k=x*x;
    if(n==k)
        printf("%d is a square number",n);
    else
        printf("%d is not a square number",n);
    return 0;
}
