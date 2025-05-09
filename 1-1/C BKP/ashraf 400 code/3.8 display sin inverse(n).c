#include<stdio.h>
#include<math.h>
int main()
{
    float n;
    scanf("%f",&n);
    printf("Sin inverse(%.2f)= %.2f",n,asin(n)*180/M_PI);
    return 0;
}


