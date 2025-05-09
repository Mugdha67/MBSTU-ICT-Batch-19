#include<stdio.h>
int main()
{
    int i,j,n,a[100],temp;
    printf("how many number : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        int f=0;
        for(j=0;j<n-1-i;j++)
        {
             if(a[j]>a[j+1])
            {
                temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
        f=1;
            }
        }
        if(f==0)
        {
            break;
        }
    }
        for(i=0;i<n;i++)
        printf("%d ",a[i]);

    }
