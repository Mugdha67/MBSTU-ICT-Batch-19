#include<stdio.h>
int main()
{
    int s,a[100],i,count=0;

    for(i=1;i<=100;i++)
    {
        a[i]=rand()%500+100;
        printf("%d\n",a[i]);
    }
    scanf("%d",&s);
    for(i=0;i<100;i++)
    {
        if(a[i]==s)
        {
            printf("Data is found\n");
            count++;
            break;
        }
    }
    if(count==0)
    {
        printf("Not Found\n");
    }
    return 0;
}
