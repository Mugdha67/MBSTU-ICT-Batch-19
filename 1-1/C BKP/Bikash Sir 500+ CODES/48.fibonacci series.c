#include<stdio.h>
int main()
{
    int n,i,a,b,sum=0;
a=0,b=1;
    scanf("%d",&n);
    printf("0\t1\t");
    for(i=1;i<=n-2;i++){
        sum=a+b;
      printf("%d\t",sum);
      a=b;
      b=sum;
    }
      return 0;
}
// fibonacci series
