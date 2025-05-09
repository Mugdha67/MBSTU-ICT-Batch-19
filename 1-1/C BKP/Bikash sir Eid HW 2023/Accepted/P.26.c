#include<stdio.h>
int main()
{
    int T,count;
    double x;
    scanf("%d",&T);
    while(T--)
        {
        scanf("%lf",&x);
        count = 0;
        while(x>=1.0)
        {
            x=x/2;
            count++;
        }
        printf("%d days\n",count);
    }
    return 0;
}
