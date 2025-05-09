#include<stdio.h>

int main(){
    int t;
    long long int a,b,c,i,j;
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld%lld", &a,&b,&c);
        if(a > b){
            j = b;
        }
        else{
            j = a;
        }
        for(i = j; i <=c; i++){
            if(i % (a*b) == 0){
                printf("%lld\n", i);
            }
        }
        printf("\n");
    }
    return 0;
}
