#include<stdio.h>
int remainder(int a,int b)
{
    return a%b;
}
int main()
{
    int x,y;
    printf("Enter the value for x and y:\n");
    scanf("%d%d",&x,&y);
    int ans=remainder(x,y);
    printf("The remainder is : %d\n",ans);
    return 0;
}
