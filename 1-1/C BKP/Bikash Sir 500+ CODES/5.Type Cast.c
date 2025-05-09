//Type Cast
#include<stdio.h>
int main()
{
    int a,b;
    float result;
    printf("Insert a and b\n",a,b);
    scanf("%d%d",&a,&b);
    result=(float)a/b;
    printf("%.2f",result);
    return 0;
}
