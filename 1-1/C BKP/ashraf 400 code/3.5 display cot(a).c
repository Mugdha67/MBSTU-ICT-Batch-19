#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    scanf("%d",&a);
    printf("Cot(%d)= %.2f",a,(float)(1/tan(a*M_PI/180)));
    return 0;
}

