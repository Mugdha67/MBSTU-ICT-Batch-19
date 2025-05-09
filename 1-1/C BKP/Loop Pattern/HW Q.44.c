#include<stdio.h>
int main()
{
    int x,y;
    for(x=4;x>=1;x--)
    {
        for(y=1;y<=x;y++)
            printf("%d",y);

        for(y=4;y>=x+1;y--)
        printf("__");



        for(y=x;y>=1;y--)
        printf("%d",y);


        printf("\n",x);
    }
}
