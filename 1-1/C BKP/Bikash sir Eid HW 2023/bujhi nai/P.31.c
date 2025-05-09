#include<stdio.h>

int main(){
    int t,i,n;
    int arr[5] = {6,28,496,8128,33550336};
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 0; i < 5; i++){
            if(arr[i] < n){
                printf("%d\n", arr[i]);
            }
            else{
                break;
            }
        }
    }
    return 0;
}
