#include<stdio.h>
#include<string.h>
int main()
{
    {
        char s[1001];
        int i,l,count[26];
        gets(s);
        l=strlen(s);
        for(i=0; i<26; i++)
        {
            count[i]=0;
        }
        for(i=0; i<=l; i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                count[s[i]-'a']++;
            }
            if(s[i]>='A'&&s[i]<='Z')
            {
                count[s[i]-'A']++;
            }
        }
        for(i=0; i<26; i++)
        {
            if(count[i]!=0)
            {
                printf("%c = %d\n",'a'+i,count[i]);
            }
             for(i=0; i<26; i++)
        {
            if(count[i]!=0)
            {
                printf("%c = %d\n",'A'+i,count[i]);
            }
        }
        printf("\n");
    }
    }
    return 0;
}
