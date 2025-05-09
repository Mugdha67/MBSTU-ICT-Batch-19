#include<stdio.h>
void sum(int n)
{
    int i,sum=0;
    for(i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            sum=sum+i;
        }
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
