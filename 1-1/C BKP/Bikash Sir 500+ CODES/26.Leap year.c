#include<stdio.h>
int main()
{
    int year;
    printf("Enter any year:");
    scanf("%d",&year);
    if(year%400==0 || year%4==0 && year%100!=0)
    {
        printf("%d is Leap Year",year);
    }
    else
    {
        printf("%d is not Leap Year",year);
    }
    return 0;
}
