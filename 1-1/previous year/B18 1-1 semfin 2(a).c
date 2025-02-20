#include<stdio.h>
int main()
{
    int i=4,j=-1,k=0,w,x,y,z;
    w=i||j||k;
    x=i&&j&&k;
    y=i||j&&k;
    z=i&&j||k;
    printf("w=%d\n",w);
    printf("x=%d\n",x);
    printf("y=%d\n",y);
    printf("z=%d\n",z);
    return 0;
}
