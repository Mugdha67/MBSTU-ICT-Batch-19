//Remainder
#include<stdio.h>
int main()
{
    int mim,atik,result,remainder;
    printf("Insert mim and atik where mim>atik:\n");
    scanf("%d%d",&mim,&atik);
    result=mim/atik;
    remainder=mim%atik;
    printf("result=%d\n",result);
    printf("remainder=%d\n",remainder);
    return 0;
}
