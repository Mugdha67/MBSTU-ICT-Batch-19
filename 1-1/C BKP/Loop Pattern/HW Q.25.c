#include<stdio.h>
int main()
{
    int x,y;
    for(x=1;x<=5;x++)
    {
        for(y=1;y<=x;y++)
            printf("%d ",x);

            printf("\n",x);
    }
    for(x=4;x>=1;x--)
    {
        for(y=x;y>=1;y--)
            printf("%d ",x);

            printf("\n",x);
    }
    return 0;
}
