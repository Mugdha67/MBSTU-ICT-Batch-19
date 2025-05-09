#include<stdio.h>
int main()
{
    int x,y;
    for(x=1;x<=5;x++)
    {
        for(y=5;y>=1;y--)
        {
            printf("%d",y);
        }
        printf("\n",x);
    }
    return 0;
}
