#include<stdio.h>
#include<string.h>
int main()
{
    int T,count=0;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        char s[10001];
        scanf(" %[^\n]",s);
        char* token=strtok(s," ");
        while(token!=0)
        {
            count++;
            token=strtok(0," ");
        }
        printf("Count = %d\n",count);
        count=0;
    }
    return 0;
}

