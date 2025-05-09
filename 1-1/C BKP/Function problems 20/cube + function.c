#include<stdio.h>
int cube(int a)
{
    return a*a*a;
}
int main()
{
    int x;
    scanf("%d",&x);
    int ans=cube(x);
    printf("Cube of %d is: %d\n",x,ans);
    return 0;
}
