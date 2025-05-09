#include<stdio.h>
int main()
{
    int x,y;
    for(x=1;x<=5;x++)
    {
        for(y=5;y>x;y--)
        {
            printf("  ",y);
        }
        for(y=1;y<=((2*x)-1);y++)
        {
            printf("%d ",y);
        }
        printf("\n",x);
    }
    return 0;
}

/*

            1
          1 2 3
        1 2 3 4 5
      1 2 3 4 5 6 7
    1 2 3 4 5 6 7 8 9

*/
