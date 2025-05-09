#include<stdio.h>
int main()
{
    int x,y,z;
    for(x=1;x<=6;x++)
    {
        for(y=x;y<6;y++)
        {
            printf("\t",y);
        }
        for(z=1;z<=2*x-1;z++)
        {
            printf("*\t",z);
        }
        printf("\n",x);
    }
    return 0;
}
