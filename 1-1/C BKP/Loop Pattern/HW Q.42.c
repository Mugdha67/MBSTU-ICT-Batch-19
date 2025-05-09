#include<stdio.h>
int main()
{
    int x,y;
    for(x=5;x>=1;x--){
        for(y=x;y>=1;y--)
        printf("%c",y+64);
    printf("\n",x);
    }
    return 0;
}
