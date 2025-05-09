#include<stdio.h>

int main(){
    int t,i,p,q,c,x;

    scanf("%d", &t);
    while(t--){
        x = 1;
        scanf("%d%d%d", &p,&q,&c);
        for(i = 0; i < q; i++){
            x = x * p;
        }
        printf("Result = %d\n", x % c);
    }
    return 0;
}
