#include<stdio.h>
int main()
{
    int  a, b;
    a=100;b=100;
    printf("%d %d %d %d",a++,a++,++a,a);//102 101 103 103
    printf("\n%d",a);//103
    printf("\n%d %d %d %d",--b,b--,++b,b++);//100 102 100 100
    printf("\n%d",b);//100
    return 0;
}
