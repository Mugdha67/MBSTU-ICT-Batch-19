#include<stdio.h>
int main(){
    int t,i;
    unsigned long long int n,m,sum;
    scanf("%d", &t);
    while(t--){
        sum = 0;
        scanf("%llu", &n);
        m = n;
        for(i = 0; i <= n/2; i++){
            if(n % i == 0){
                sum = sum + i;
            }
        }
        if(sum == m){
            printf("YES, %llu is a perfect number!\n", m);
        }
        if(sum != m){
            printf("NO, %llu is not a perfect number!\n", m);
        }
    }
}
