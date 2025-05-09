#include<stdio.h>
int main()
{
    int x,y,z=1;
    for(x=0;x<4;x++)
    {
        for(y=0;y<=3-x;y++)
        {
            printf(" ",y);
        }

        for(y=0;y<=x;y++)
        {
           if(x==0||y==0)
            z=1;
           else
            z=z*(x-y+1)/y;
            printf("%d ",z);
        }
            printf("\n",x);
    }
    return 0;
}
