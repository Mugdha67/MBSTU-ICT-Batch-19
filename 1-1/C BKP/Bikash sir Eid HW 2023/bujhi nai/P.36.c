#include <stdio.h>
#include <string.h>

int main()
{
    char S[10001][100], temp[10001];
    int t, n, i, j;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%s", S[i]);
        }
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (strcmp(S[i], S[j]) > 0)
                {
                    strcpy(temp, S[i]);
                    strcpy(S[i], S[j]);
                    strcpy(S[j], temp);
                }
            }
        }
        printf("\n");
        for (i = 0; i < n; i++)
        {
            printf("%s\n", S[i]);
        }
        printf("\n");
    }
    return 0;
}
