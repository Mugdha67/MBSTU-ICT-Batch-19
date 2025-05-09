#include<stdio.h>
float Asquare(float a)
{
    return a*a;
}
int main()
{
    float x;
    printf("Length of the sides:\n");
    scanf("%f",&x);
    float ans=Asquare(x);
    printf("Area of the Square is : %f\n",ans);
    return 0;
}
