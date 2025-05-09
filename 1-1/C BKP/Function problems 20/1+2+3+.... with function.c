#include<stdio.h>
void sum(int a)
{
    int i,sum=0;
    for(i=1;i<=a;i++)
    {
        sum=sum+i;
    }
    printf("%d",sum);
}
int main()
{
    int x;
    scanf("%d",&x);
    sum(x);
    return 0;
}
