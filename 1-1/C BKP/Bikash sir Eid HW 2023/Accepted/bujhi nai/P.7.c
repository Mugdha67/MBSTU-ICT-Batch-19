#include<stdio.h>
#include<stdlib.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
    char line[100000];
    scanf(" %[^\n]",line);
    char *p,*e;
    long input;
    int count=0;
    p=line;
    for(p=line;;p=e)
    {
        input=strtol(p,&e,10);
        if(p==e)
        {
            break;
        }
        count++;
    }
    printf("%d\n",count);
    }
    return 0;
}
