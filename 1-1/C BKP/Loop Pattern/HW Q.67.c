#include<stdio.h>
int main()
{
    int i,j;
    for(i=1;i<=10;i+=2)
    {
        for(j=9;j>=i;j--)
        {
            printf("*",j);
        }
        printf("\n",i);
    }
    return 0;
}
/*

*********
*******
*****
***
*

*/
