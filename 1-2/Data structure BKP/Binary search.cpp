#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[100],i,n,f,l,m,mid,p;
    printf("Enter the number of the elements:");
    scanf("%d",&n);
    printf("Enter %d values:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    l=0;
    m=n-1;
    cout<<"Enter the value you want to find:";
    scanf("%d",&f);
   do{
    while(l<=m)
    {
        mid=(l+m)/2;
            if(a[mid]==f)
        {
            printf("%d is found in Index[%d]\n",f,mid);
            break;
        }
        else if(a[mid]<f)
        {
            l=mid+1;
        }
        else if(a[mid]>f)
        {
            m=mid-1;
        }
    }

    if(a[mid]!=f)
    printf("%d is not found\n");

    printf("Press 0 to terminate the program or Press 1 to find another value:");
    scanf("%d",&p);
    if(p==0)
        break;
        else
            printf("Enter the value you want to find:");
l=0,m=n-1;
   }while(scanf("%d",&f)==1);

    return 0;
}
