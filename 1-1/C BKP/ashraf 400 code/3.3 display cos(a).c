#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    scanf("%d",&a);
    printf("Cos(%d)= %.2f",a,(float)cos(a*M_PI/180));
    return 0;
}
