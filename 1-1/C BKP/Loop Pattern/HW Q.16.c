#include<stdio.h>
int main()
{
    int x,y,z;
    for(x=5;x>=1;x--)
    {
        for(y=5;y>x;y--)
        {
            printf("\t",y);
        }
        for(z=1;z<=x;z++)
        {
            printf("%d\t",z);
        }
        printf("\n",x);
    }
    return 0;
}
