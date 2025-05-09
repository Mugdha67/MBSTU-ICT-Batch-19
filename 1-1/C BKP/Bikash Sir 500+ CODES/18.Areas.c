#include<stdio.h>
int main()
{
    int n;
    float a,b,h,r;
    float A1,A2,A3,A4;
    printf("Enter 1 for the area of triangle\nEnter 2 for the area of circle\nEnter 3 for the area of conic\nEnter 4 for the area of rectangle\n",n);
    scanf("%d",&n);
    if(n==1)
    {
        printf("Enter base & height");
        scanf("%f%f",&b,&h);
        A1=0.5*b*h;
        printf("the area of triangle is %f",A1);
    }
    else if(n==2)
    {
        printf("Enter radius:\n",r);
        scanf("%f",&r);
        A2=3.14*r*r;
        printf("Area of Circle:%f\n",A2);
    }
    else if(n==3)
    {
         printf("Enter radius and height:\n",r,h);
         scanf("%f%f",&r,&h);
         A3=3.14*r*(r+h);
         printf("Total surface of Cone:%f\n",A3);
    }
    else if(n==4)
    {
         printf("Length and Breadth:\n",a,b);
         scanf("%f%f",&a,&b);
         A4=a*b;
         printf("Area of Rectangle:%f",A4);
    }
    return 0;
}
