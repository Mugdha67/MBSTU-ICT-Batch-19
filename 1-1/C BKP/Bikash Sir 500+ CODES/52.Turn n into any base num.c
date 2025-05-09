#include<stdio.h>
int main()
{
    int a[100],c=0,i=0,n,b;
    scanf("%d",&n);
    scanf("%d",&b);
        while(n>0)
        {
            a[i]=n%b;
            n=n/b;
            i++;
            c++;
        }
        for(i=c-1;i>=0;i--)
        {
            printf("%d",a[i]);
        }
        return 0;
}
