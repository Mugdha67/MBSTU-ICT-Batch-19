#include<stdio.h>
#include<math.h>
int main()
{
    float n;
    scanf("%f",&n);
    printf("Cot inverse(%.2f)= %.2f",n,(atan(1.0/n)*180/M_PI));
    return 0;
}
//??
