//Find the largest number
#include<stdio.h>
int main()
{
    int a,b,c,d;
    printf("Enter the values:\n");
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a>b&&a>c&&a>d)
    {
        printf("%d is largest\n",a);
    }
    else if(b>a&&b>c&&b>d)
    {
        printf("%d is largest\n",b);
    }
    else if(c>a&&c>b&&c>d)
    {
        printf("%d is largest\n",c);
    }
    else
    {
        printf("%d is largest\n",d);
    }
    return 0;
}

