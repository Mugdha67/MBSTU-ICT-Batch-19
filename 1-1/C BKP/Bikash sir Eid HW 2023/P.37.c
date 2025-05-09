
#include<stdio.h>

int main(){
    int t,a;
    long int num,x;
    scanf("%d", &t);
    while(t--){
        x = 0;
        scanf("%ld", &num);
        while(num > 0){
            a = num % 10;
            num = num / 10;
            x = a + x * 10;
        }
        printf("%ld\n", x);
    }
    return 0;
}
