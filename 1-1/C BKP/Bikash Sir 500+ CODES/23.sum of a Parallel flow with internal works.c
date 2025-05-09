//sum of a Parallel flow with internal works
#include<stdio.h>
int main()
{
    int sum=0,i;
    for(i=1;i<=6;i++)
    {
      printf("i= %d ",i);
        sum=sum+i;
        printf("sum= %d \n",sum);
    }
    printf("\n\n\n Final sum %d\n\n",sum);
    printf("Final i value %d\n",i);
    return 0;
}
