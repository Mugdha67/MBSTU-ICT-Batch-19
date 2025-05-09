#include<stdio.h>
int main()
{
    int i,N,num,a[100001],m,t;
    scanf("%d", &t);
    while(t--){
     scanf("%d",&N);
    for(i=1;i<=N;i++)
        a[i]=0;
    for(i=0;i<N-1;i++)
    {
        scanf("%d",&num);
        a[num]=1;
    }
    for(i=1;i<=N;i++)
    {
        if(a[i]==0)
        {
            m=i;
            break;
        }
    }
    printf("%d\n",m);
    }
    return 0;
}
