#include<stdio.h>
int main()
{
    int x,y;
    for(x=6;x>=1;x--)
    {
        for(y=1;y<=x;y++)
        {
            printf("%c",y+64);
        }
        for(y=x;y>=1;y--)
        {
            printf("%c",y+64);
        }
        printf("\n",x);
    }
    return 0;
}

/*

ABCDEFFEDCBA
ABCDEEDCBA
ABCDDCBA
ABCCBA
ABBA
AA

*/
