//m to n all odd numbers with count
#include<stdio.h>
int main()
{
    int m,n,i,count=0;
    printf("Enter m & n where m<n:\n",m,n);
    scanf("%d%d",&m,&n);
    for(i=m;i<=n;i++)
        if(i%2!=0)
    {
        printf("%d\n",i);
        count=count+1;
    }
    printf("count %d",count);
    return 0;
}
