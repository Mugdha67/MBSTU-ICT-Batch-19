#include<stdio.h>
int main()
{
    char s[6]="INDIA";
    int i,j,n;
    n=strlen(s);

    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
            printf("%c",s[j]);
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n-i-1;j++)
            printf("%c",s[j]);
        printf("\n");
    }
    return 0;
}
