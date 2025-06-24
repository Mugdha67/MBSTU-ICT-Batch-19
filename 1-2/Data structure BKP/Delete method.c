#include<stdio.h>
int main()
{
    int i,n,b;
    printf("Enter the element number:");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d values below:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The index you want to delete:");
    scanf("%d",&b);
    for(i=b;i<n;i++)
    {
        a[i]=a[i+1];
    }
    for(i=0;i<n-1;i++)
    {
     printf("Index[%d]=%d\n",i,a[i]);
    }
    return 0;
}
