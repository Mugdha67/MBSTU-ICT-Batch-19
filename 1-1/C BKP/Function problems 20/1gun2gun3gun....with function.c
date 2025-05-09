#include<stdio.h>
void d(int a)
{
    int i,d=1;
    for(i=a;i>=1;i--)
    {
        d=d*i;
    }
    printf("%d",d);
}
int main()
{
    int x;
    scanf("%d",&x);
    d(x);
    return 0;
}
