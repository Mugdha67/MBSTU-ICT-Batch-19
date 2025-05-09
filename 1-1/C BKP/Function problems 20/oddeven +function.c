#include<stdio.h>
void oddeven(int a)
{
    if(a%2==0)
        printf("even\n");
    else
        printf("odd\n");
}
int main()
{
    int x;
    scanf("%d",&x);
    oddeven(x);
    return 0;
}
