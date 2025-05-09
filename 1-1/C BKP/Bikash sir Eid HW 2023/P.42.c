#include<stdio.h>
int main()
{
    int T, i, k;
    scanf("%d", &T);
    for ( i = 0; i < T; i++)
    {
        int num;
        scanf("%d", &num);
        for ( k = num; k >= 0; k--)
            {
                if(k==0)
                    printf("1");
                else if(k == 1)
                    printf("2 + ");
                else
                    printf("2^%d + ", k);
            }
        printf("\n");
    }
    return 0;
}
