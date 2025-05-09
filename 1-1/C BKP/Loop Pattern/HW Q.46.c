#include<stdio.h>
int main()
{
    int x,y;
    for(x=6;x>=1;x--)
    {
        for(y=1;y<=x;y++)
        {
            printf("%d",y);
        }
        for(y=x;y>=1;y--)
        {
            printf("%d",y);
        }
        printf("\n",x);
    }
    return 0;
}

/*

123456654321
1234554321
12344321
123321
1221
11

*/
