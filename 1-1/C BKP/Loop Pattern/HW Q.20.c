#include<stdio.h>
int main()
{
    int x,y,count=0;
    for(x=1;x<=4;x++)
    {
        for(y=1;y<=x;y++){
                count++;
            printf("%d ",count);
        }

        printf("\n",x);
    }
    return 0;
}
