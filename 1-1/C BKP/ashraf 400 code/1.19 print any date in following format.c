#include<stdio.h>
int main()
{
    int d,m,y;
    scanf("%d%*c%d%*c%d",&d,&m,&y);
    printf("\nDay= %d\nMonth= %d\nYear= %d",d,m,y);
    return 0;
}
/*
DD/MM/YYYY
DD-MM-YYYY
DD MM YYYY
DD,MM,YYYY
.....
