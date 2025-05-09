#include<stdio.h>
int sub(int a,int b)
{
    return a-b;
}
int main()
{
    int x,y;
    printf("Enter the value for x and y:\n");
    scanf("%d%d",&x,&y);
    int ans=sub(x,y);
    printf("The sub is : %d\n",ans);
    return 0;
}


