#include<stdio.h>
void sum(int a)
{
    int i;
    for(i=1;i<=a;i++)
    printf("%d ",i);
}
int main()
{
    int x;
    scanf("%d",&x);
    sum(x);
    return 0;
}
