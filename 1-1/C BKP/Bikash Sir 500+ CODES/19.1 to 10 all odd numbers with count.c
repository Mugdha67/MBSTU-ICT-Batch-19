//19.1 to 10 all odd numbers with count
#include<stdio.h>
int main()
{
    int i,count=0;
    for(i=1;i<=10;i++)
        if(i%2!=0)
    {
        printf("%d\n",i);
        count=count+1;
    }
    printf("count %d",count);
    return 0;
}
