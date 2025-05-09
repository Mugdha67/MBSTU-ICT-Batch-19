#include<stdio.h>
int main()
{
    int a,b,r,GCD,LCM;
    scanf("%d%d",&a,&b);
    LCM=a*b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        GCD=a;
        printf("GCD:%d\n",GCD);

      LCM=LCM/GCD;
      printf("LCM:%d\n",LCM);
    return 0;
}

/*#include<stdio.h>
int main()
{
    int a,b,c,x,y,i;
    scanf("%d%d",&a,&b);
    x=a*b;
    if(a<b)
    {
        c=a;
    }
    else
    {
        c=b;
    }
    for(i=c;i>=1;i--)
    {
        if(a%i==0&&b%i==0)
        {
            printf("GCD=%d\n",i);
            break;
        }
    }
    y=x/i;
    printf("LCM=%d\n",y);
    return 0;
}*/
