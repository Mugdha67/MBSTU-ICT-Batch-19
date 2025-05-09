#include<stdio.h>
int main()
{
    int x,y;
    for(x=1;x<=4;x++)
    {
        for(y=4;y>x;y--)
            printf(" ",y);

        for(y=y;y>=1;y--)
            printf("%d",y);

        for(y=2;y<=x;y++)
            printf("%d",y);

        printf("\n",x);
    }
     for(x=3;x>=1;x--)
    {
        for(y=3;y>=x;y--)
            printf(" ",y);

        for(y=x;y>=1;y--)
            printf("%d",y);

        for(y=2;y<=x;y++)
            printf("%d",y);

        printf("\n",x);
    }
    return 0;
}


