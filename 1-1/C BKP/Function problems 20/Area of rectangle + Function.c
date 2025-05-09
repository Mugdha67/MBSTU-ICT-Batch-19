#include<stdio.h>
float Arectangle(float a,float b)
{
    return a*b;
}
int main()
{
    float x,y;
    printf("Length and Breadth:\n",x,y);
    scanf("%f%f",&x,&y);
    float ans=Arectangle(x,y);
    printf("Area of Rectangle:%f\n",ans);
    return 0;
}
