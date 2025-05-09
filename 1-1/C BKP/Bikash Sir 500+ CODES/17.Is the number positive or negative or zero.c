#include<stdio.h>
int main()
{
    int n;
    printf("Enter the value:\n",n);
    scanf("%d",&n);
    if(n==0)
    {
        printf("The Number is Zero");
    }
    else if(n>0)
    {
        printf("%d is positive",n);
    }
    else
    {
        printf("%d is negative",n);
    }
return 0;
}
