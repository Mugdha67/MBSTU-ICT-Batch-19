#include<stdio.h>
int main()
{
    int x,y;
    for(x=1;x<=5;x++)
    {
        for(y=1;y<=x-1;y++)
            printf("  ",y);
        for(y=x;y<=5;y++)
            printf("%c ",y+64);
        for(y=4;y>=x;y--)
            printf("%c ",y+64);
        printf("\n",x);
    }
    return 0;
}
