#include<stdio.h>
int main()
{
    int x,y;
    for(x=1;x<=4;x++)
    {
        for(y=1;y<=x;y++)
            printf("%c ",x+64);
        printf("\n",x);
    }
    return 0;
}
