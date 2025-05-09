#include<stdio.h>
int main()
{
    int x,y,z;
    for(x=1;x<=5;x++)
    {
        for(y=x;y<5;y++)
        printf(" ",y);

        for(z=x;z>=1;z--)
            printf("%d",z);

        printf("\n",x);
    }
    return 0;
}
