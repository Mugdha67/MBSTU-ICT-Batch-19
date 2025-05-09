#include<stdio.h>
int main()
{
    int T,i,r1,r2,B,b;
    float d,w;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d%d%d",&r1,&r2,&B);
        b=(300-B);
        d=(r2/(b*1.0))*6;
        if(r1<r2)
        {
            w=0.00;
        }
        else
            {
        w=(r1+1-r2)/(B*1.0);
        w=w*6;
            }
        printf("%.2f %.2f\n",d,w);
    }
    return 0;
}
