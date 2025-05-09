#include<stdio.h>
int main()
{
    int x,y;
    for(x=5;x>=1;x--)
    {
        for(y=1;y<=5;y++)
        {
            printf("%d",x);
        }
        printf("\n",x);
    }
    return 0;
}
