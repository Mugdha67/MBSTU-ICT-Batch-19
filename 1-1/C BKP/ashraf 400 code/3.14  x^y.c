#include<stdio.h>
#include<math.h>
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d to the power %d= %.01f",x,y,pow(x,y));
    return 0;
}
