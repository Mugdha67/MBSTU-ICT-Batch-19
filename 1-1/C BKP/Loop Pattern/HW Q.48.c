#include<stdio.h>
int main()
{
    int x,y;
    for(x=1;x<=5;x++)
    {
        for(y=5;y>x;y--)
        {
            printf(" ",y);
        }
        for(y=1;y<=((2*x)-1);y++)
        {
            printf("%d",x);
        }
        printf("\n",x);
    }
    return 0;
}

/*

       1
      222
     33333
    4444444
   555555555

*/
