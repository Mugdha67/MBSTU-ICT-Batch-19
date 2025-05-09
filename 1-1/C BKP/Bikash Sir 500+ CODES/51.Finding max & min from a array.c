#include<stdio.h>
int main()
{
    int s,a[101],i,count=0;

    for(i=0;i<100;i++)
    {
        a[i]=rand()%500+100;
        printf("%d\n",a[i]);
    }
        int MIN=a[0];
        int MAX=a[0];
        for(i=1;i<100;i++)
    {
        if(a[i]<MIN)
        {
            MIN=a[i];
        }
        if(a[i]>MAX)
        {
            MAX=a[i];
        }
    }
    printf("Maximum Number is: %d\n",MAX);
    printf("Minimum Number is: %d\n",MIN);
    return 0;
}

