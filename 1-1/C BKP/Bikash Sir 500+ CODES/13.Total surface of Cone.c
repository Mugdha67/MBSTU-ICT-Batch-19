//Total surface of Cone
#include<stdio.h>
int main()
{
    float r,h,area;
    printf("Enter radius and height:\n",r,h);
    scanf("%f%f",&r,&h);
    area=3.14*r*(r+h);
    printf("Total surface of Cone:%f\n",area);
    return 0;
}
