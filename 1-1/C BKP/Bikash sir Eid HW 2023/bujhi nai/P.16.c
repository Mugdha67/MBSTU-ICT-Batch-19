#include<stdio.h>
#include<string.h>

int main(){
    int t,i,j,k,len;
    char S[1002], single[1002];
    scanf("%d", &t);
    while(t--){
        scanf(" %[^\n]", S);
        len = strlen(S);
        for(i = 0, j = 0; i < len; i++){
            if(S[i] != ' '){
                single[j] = S[i];
                j++;
            }
            else if( j > 0){
                single[j] = '\0';
                for(k = strlen(single)- 1; k >= 0; k--){
                    printf("%c", single[k]);
                }
                printf(" ");
                j = 0;
            }
        }
        if( j > 0){
                single[j] = '\0';
                for(k = strlen(single)- 1; k >= 0; k--){
                    printf("%c", single[k]);
                }
            }
        printf("\n");
    }
    return 0;

}
