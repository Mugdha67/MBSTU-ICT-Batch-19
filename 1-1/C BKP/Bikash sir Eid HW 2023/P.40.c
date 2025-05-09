#include <stdio.h>

int main(){
    int t, i, x, k, sum, multi;
    scanf("%d", &t);
    while (t--){
        sum = 0;
        multi = 1;
        scanf("%d%d", &x, &k);
        for (i = 1; i <= k; i++){
            multi = multi * x;
            sum = sum + multi;
        }
        printf("Result = %d\n", sum + 1);
    }
    return 0;
}
