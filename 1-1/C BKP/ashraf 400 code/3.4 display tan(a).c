#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    scanf("%d",&a);
    printf("Tan(%d)= %.2f",a,(float)tan(a*M_PI/180));
    return 0;
}

