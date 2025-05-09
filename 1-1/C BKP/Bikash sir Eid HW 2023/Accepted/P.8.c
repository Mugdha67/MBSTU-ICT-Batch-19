#include<stdio.h>
int main()
{
    int T,i,n1,n2,n3,temp;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d%d%d",&n1,&n2,&n3);
        if(n1>n2)
        {
            temp=n1;
            n1=n2;
            n2=temp;
        }
        if(n2>n3)
        {
            temp=n2;
            n2=n3;
            n3=temp;
        }
        if(n1>n2)
        {
            temp=n1;
            n1=n2;
            n2=temp;
        }
        printf("Case %d: %d %d %d\n",i,n1,n2,n3);
    }
    return 0;
}
