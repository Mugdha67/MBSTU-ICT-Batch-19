#include<stdio.h>
int main()
{
    int x,y;
    for(x=5;x>=1;x--)
    {
        for(y=5;y>x;y--)
            printf("\t",y);

        for(y=1;y<=x;y++)
            printf("%d\t",y);

        for(y=x-1;y>=1;y--)
            printf("%d\t",y);

        printf("\n",x);
    }
    return 0;
}

