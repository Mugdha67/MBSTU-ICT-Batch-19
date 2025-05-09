#include<stdio.h>
int square(int a)
{
    return a*a;
}
int main()
{
    int x;
    printf("Enter the value for x :\n");
    scanf("%d%",&x);
    int ans=square(x);
    printf("The square of %d is : %d\n",x,ans);
    return 0;
}



