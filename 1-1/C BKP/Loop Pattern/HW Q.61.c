#include<stdio.h>
int main()
{
   int i,j;
for(i=1;i<=5;i++)
{
for(j=1;j<i;j++)
{
printf(" ",j);
}
for(j=i;j<=5;j++)
{
printf("%d ",j);
}

printf("\n",i);

}
    return 0;
}

/*

1 2 3 4 5
 2 3 4 5
  3 4 5
   4 5
    5

*/
