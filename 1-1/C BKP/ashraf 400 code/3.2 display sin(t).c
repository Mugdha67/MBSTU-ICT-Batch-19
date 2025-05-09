#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    printf("Sin(%d)= %.2f",t,(float)sin(t*M_PI/180));
    return 0;
}
