//Total surface area of Cylinder
#include<stdio.h>
int main()
{
    float r,h,area;
    printf("Enter radius and height:\n",r,h);
    scanf("%f%f",&r,&h);
    area=2*3.14*r*(r+h);
    printf("Total surface area of Cylinder:%f",area);
    return 0;
}
