#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[1000],i;
    for(i=1;i<=5;i++)
        a[i]=rand()%30+50;

    for(i=1;i<=5;i++)
        printf("index[%d]=%d\n",i,a[i]);

    return 0;
}
