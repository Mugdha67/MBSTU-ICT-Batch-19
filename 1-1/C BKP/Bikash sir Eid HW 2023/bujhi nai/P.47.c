#include<stdio.h>

int main(){
    int t,i,j,n1,n2,temp;
    int arr1[100],arr2[100],arrt[200];
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n1);
        for(i = 0; i < n1; i++){
            scanf("%d", &arr1[i]);
        }
        scanf("%d", &n2);
        for(i = 0; i < n2; i++){
            scanf("%d", &arr2[i]);
        }
        for(i = 0; i < n1; i++){
            arrt[i] = arr1[i];
        }
        for(i = 0; i < (n1+n2); i++){
            arrt[i+n1] = arr2[i];
        }
        for(i = 0; i < (n1+n2); i++){
            for(j = i; j < (n1+n2); j++){
                if(arrt[i] < arrt[j]){
                    continue;
                }
                else{
                    temp = arrt[i];
                    arrt[i] = arrt[j];
                    arrt[j] = temp;
                }
            }
        }
        for(i = 0; i < (n1+n2); i++){
            printf("%d ", arrt[i]);
        }
        printf("\n");
    }
    return 0;
}
