#include<stdio.h>
int main()
{
    int a[15],i,t,n,b;
    printf("How many element do you want to insert:");
    scanf("%d",&b);
    printf("Enter %d values below:\n",b);
    for(i=0; i<b; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the index you want to insert:");
    scanf("%d",&n);
    a[b]=0;
    for(i=b; i>n; i--)
    {
        if(i>i-1)
        {
            t=a[i];
            a[i]=a[i-1];
            a[i-1]=t;
        }
    }
    printf("Enter the new value:");
    scanf("%d",&a[n]);
    for(i=0; i<b+1; i++)
    {
        printf("index[%d]=%d\n",i,a[i]);
    }

    return 0;
}

