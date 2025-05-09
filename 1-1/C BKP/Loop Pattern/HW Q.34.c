#include<stdio.h>
int main()
{
    int x,y,z;
    for(x=1;x<=4;x++)
    {
        for(y=x;y<4;y++)
        {
            printf(" ",y);
        }
        for(z=1;z<=2*x-1;z++)
        {
            printf("*",z);
        }
        printf("\n",x);
    }
    for(x=3;x>=1;x--)
    {
        for(y=x;y<4;y++)
        {
            printf(" ",y);
        }
        for(z=1;z<=2*x-1;z++)
        {
            printf("*",z);
        }
        printf("\n",x);
    }
    return 0;
}
