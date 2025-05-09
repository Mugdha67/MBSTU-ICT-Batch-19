//Area of an Isosceles Triangle
#include<stdio.h>
int main()
{
    float s,a,b,c,area;
    printf("Enter the values of three sides:\n");
    scanf("%f%f%f,&a,&b,&c");
    s=(a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("Area of an Isosceles Triangle:%f",area);
    return 0;
}
