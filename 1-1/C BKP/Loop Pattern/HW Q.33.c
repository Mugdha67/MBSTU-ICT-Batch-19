#include<stdio.h>
int main()
{
    int x,y,z;
    for(x=1;x<=6;x++)
    {
        for(y=1;y<=6-x;y++)
        {
            printf(" ",y);
        }

        for(z=1;z<=x;z++)
        {
            printf("%d ",z);

        }
            printf("\n",x);
    }
    return 0;
}
