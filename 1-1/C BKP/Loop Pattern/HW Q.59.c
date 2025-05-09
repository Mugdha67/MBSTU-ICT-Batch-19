#include<stdio.h>
int main()
{
   int i,j;
for(i=1;i<=5;i++)
{
for(j=1;j<=i;j++)
{
if(i%2==1)
{
printf("%d",j);
}
else
{
printf("%c",j+64);
}
}
printf("\n",i);

}
    return 0;
}

/*

1
AB
123
ABCD
12345

*/
