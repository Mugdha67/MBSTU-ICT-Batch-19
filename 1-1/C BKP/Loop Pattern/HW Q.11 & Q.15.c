#include<stdio.h>
int main()
{
    int x,y;
    for(x=5;x>=1;x--)
    {
        for(y=1;y<=x;y++)
        {
            printf("%d",y);
        }
        printf("\n",x);
    }
    return 0;
}

