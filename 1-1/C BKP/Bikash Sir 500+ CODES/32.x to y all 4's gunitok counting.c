#include<stdio.h>
int main()
{
    int x=1,y,count=0;
    printf("Enter the value of x & y where x<y:\n");
    scanf("%d%d",&x,&y);
    while(x<y)
    {
        if(x%4==0)
            count=count+1;
        x++;
    }
    printf("%d\n",count);
    return 0;
}
