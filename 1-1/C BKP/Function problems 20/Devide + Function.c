#include<stdio.h>
int devide(int a,int b)
{
    return a/b;
}
int main()
{
    int x,y;
    printf("Enter the value for x and y:\n");
    scanf("%d%d",&x,&y);
    int ans=devide(x,y);
    printf("The Devision is : %d\n",ans);
    return 0;
}



