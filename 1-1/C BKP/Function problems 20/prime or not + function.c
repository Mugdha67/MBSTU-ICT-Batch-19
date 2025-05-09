#include<stdio.h>
void num(int n)
{
    int i,p=0;
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            p++;
        }
    }
        if(p>0)
        {
            printf("NOT PRIME NUMBER\n");
        }
        else if(p==0)
        {
            printf("PRIME NUMBER\n");
        }
    }
    int main()
    {
        int x;
        scanf("%d",&x);
        num(x);
        return 0;
    }
