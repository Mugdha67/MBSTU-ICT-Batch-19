#include<stdio.h>
int main(){
    int t,X,N,i;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &X,&N);
        if(X <= N){
            for(i = X; i <= N; i++){
                if(i % X == 0)
                    printf("%d\n", i);
            }
        }
        if(X > N){
            printf("Invalid!");
        }
        printf("\n");
    }
    return 0;
}
