#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    int l,i,count=0;
    scanf(" %[^\n]",s);
    l=strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i]>='!'&&s[i]<='/')
        {
            count++;
        }
        if(s[i]>=':'&&s[i]<='@')
        {
            count++;
        }
        if(s[i]>='['&&s[i]<='`')
        {
            count++;
        }
        if(s[i]>='{'&&s[i]<='~')
        {
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}
