#include<stdio.h>
int main()
{
    int x;
    printf("Insert any number: ");
    scanf("%d",&x);
    if(x%2==0)
        printf("even\n",x);
    else
        printf("odd\n",x);
    return 0;
}
