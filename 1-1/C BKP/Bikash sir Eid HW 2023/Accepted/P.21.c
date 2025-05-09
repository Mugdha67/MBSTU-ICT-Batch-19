#include<stdio.h>
#include<string.h>
int main()
{
    int T,l,i;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        char S[1001];
        gets(S);
        l=strlen(S);
        for(i=l-1;i>=0;i--)
        {
            printf("%c",S[i]);
        }
        printf("\n");
    }
    return 0;
}
