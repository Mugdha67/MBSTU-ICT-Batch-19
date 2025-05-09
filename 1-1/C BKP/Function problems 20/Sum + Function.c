#include<stdio.h>
int sum(int a,int b)
{
    return a+b;
}
int main()
{
    int x,y;
    printf("Enter the value for x and y:\n");
    scanf("%d%d",&x,&y);
    int ans=sum(x,y);
    printf("The sum is : %d\n",ans);
    return 0;
}

