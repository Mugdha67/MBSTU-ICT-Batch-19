#include<stdio.h>
#include<string.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    while(T--)
        {
            char S[101];
            scanf(" %[^\n]",S);
            for(i=0;i<strlen(S);i++)
            {
                if(S[i]>='A'&&S[i]<='Z')
                {
                printf("%d",S[i]-64);
                }
            }
        printf("\n");
        }
    return 0;
}
