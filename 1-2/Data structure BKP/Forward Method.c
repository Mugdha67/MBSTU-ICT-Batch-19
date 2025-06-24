#include<stdio.h>
int main()
{
    int Mugdha[20],i,t,n,x,b;
    printf("How many elements do you want to input first: ");
    scanf("%d",&n);
    printf("Enter %d values below:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&Mugdha[i]);
    }
    printf("Enter the index you want to insert:");
    scanf("%d",&x);
    printf("Enter the value you want to insert:");
    scanf("%d",&b);
    t=Mugdha[x];
    Mugdha[x]=b;
    for(i=x+1;i<n+1;i++)
    {
        int q=Mugdha[i];
        Mugdha[i]=t;
        t=q;
    }
    for(i=0;i<n+1;i++)
    {
        printf("Kuldip[%d]=%d\n",i,Mugdha[i]);
    }
return 0;
}
