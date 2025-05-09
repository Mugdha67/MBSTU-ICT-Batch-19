#include<stdio.h>
int multiply(int a,int b)
{
    return a*b;
}
int main()
{
    int x,y;
    printf("Enter the value for x and y:\n");
    scanf("%d%d",&x,&y);
    int ans=multiply(x,y);
    printf("The Multiplication is : %d\n",ans);
    return 0;
}
