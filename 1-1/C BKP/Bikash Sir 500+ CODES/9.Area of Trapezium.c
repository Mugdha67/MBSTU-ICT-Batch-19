//Area of Trapezium
#include<stdio.h>
int main()
{
 float a,b,h,area;
 printf("Enter the value for length, breadth and height:\n",a,b,h);
 scanf("%f%f%f",&a,&b,&h);
 area=0.5*(a+b)*h;
 printf("Area of Trapezium:%f\n",area);
 return 0;
}
