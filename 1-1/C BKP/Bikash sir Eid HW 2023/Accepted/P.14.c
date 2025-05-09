#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        int i,count=0,l;
        char s[10001],c[2];
        gets(s);
        gets(c);
        l=strlen(s);
        for(i=0;i<=l;i++)
        {
            if(s[i]==c[0])
            {
                count++;
            }
        }
        if(count>0)
        {
            printf("Occurrence of '%c' in '%s' = %d\n",c[0],s,count);
        }
        else
        {
            printf("'%c' is not present\n",c[0]);
        }
    }
    return 0;
}
