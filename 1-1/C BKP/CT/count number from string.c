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
        if(s[i]>='0'&&s[i]<='9')
        {
            count++;
        }

    }
    printf("%d\n",count);
    return 0;
}
