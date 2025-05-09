#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    scanf("%d",&a);
    printf("Sec(%d)= %.2f",a,(float)(1/cos(a*M_PI/180)));
    return 0;
}


