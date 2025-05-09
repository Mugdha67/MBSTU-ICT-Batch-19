#include<stdio.h>
int main()
{
    int x,y;
    for(x=1;x<=4;x++)
    {
        for(y=4;y>x;y--)
            printf(" ",y);

        for(y=1;y<=x;y++)
            printf("%c",y+64);

        for(y=x-1;y>=1;y--)
            printf("%c",y+64);

        printf("\n",x);
    }

    return 0;
}



