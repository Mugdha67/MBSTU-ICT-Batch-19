#include<stdio.h>
#include<stdlib.h>
int main()
{
 int a[15],i,n,x;
 printf("how many elements you want to insert:");
 scanf("%d",&n);
 for(i=0;i<n;i++){
        a[i]=rand()%99+0;
        printf("Index[%d]=%d\n",i,a[i]);
 }
 int j=0;
 for(i=0;i<n;i++)
    if(a[i]%2==1){
  a[j]=a[i];
  j++;
    }

printf("after operation:\n");
  for(i=0;i<j;i++)
    printf("Index[%d]=%d\n",i,a[i]);
}
