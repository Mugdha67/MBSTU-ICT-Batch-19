#include<stdio.h>

int main(){
    int t,i,j,n,m;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n,&m);
        for(i = 1; i <= n; i++){
            for(j = 1; j <= i; j++){
                printf("%d ", m);
            }
            printf("\n");
        }
        for(i = n-1; i > 0; i--){
            for(j = 1; j <= i; j++){
                printf("%d ", m);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
