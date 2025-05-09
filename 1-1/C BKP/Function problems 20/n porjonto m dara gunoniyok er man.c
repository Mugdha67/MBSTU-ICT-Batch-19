#include<stdio.h>
void sum(int n,int m)
{
    int i,sum=0;
    for(i=1;i<=n;i++)
    {
        if(i%m==0)
        {
            printf("%d\n",i);
        }
    }

}
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    sum(x,y);
    return 0;
}

