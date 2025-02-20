#include<stdio.h>
int main()
{
    int x,y,z;
    for(x=1;x<=5;x++)
    {
        for(y=1;y<=5-x;y++)
        {
            printf(" ",y);
        }

        for(z=1;z<=x;z++)
        {
            printf("%d ",x);

        }
            printf("\n",x);
    }
    return 0;
}
