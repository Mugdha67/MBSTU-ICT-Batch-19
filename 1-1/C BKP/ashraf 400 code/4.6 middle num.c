#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if((a<b&&b<c)||(c<b&&b<a))
    {
        printf("%d is the middle number",b);
    }
    else if((b<a&&a<c)||(c<a&&a<b))
    {
        printf("%d is the middle number",a);
    }
    else if((a<c&&c<b)||(b<c&&c<a))
    {
        printf("%d is the middle number",c);
    }
    return 0;
}

