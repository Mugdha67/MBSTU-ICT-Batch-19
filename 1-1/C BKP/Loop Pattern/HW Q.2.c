#include<stdio.h>
int main()
{
    int x,y,z;
    for(x=1;x<=5;x++)
    {
        for(y=1;y<x;y++)
        {
            printf(" \t",y);
        }
        for(z=x;z<=5;z++)
        {
            printf("#\t",z);
        }
        printf("\n",x);
    }
    return 0;
}
