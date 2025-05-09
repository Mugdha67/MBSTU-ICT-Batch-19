#include<stdio.h>
#include<string.h>

int main(){
    int t,i,j,f;
    char str1[130], str2[130];
    scanf("%d", &t);
    while(t--){
        scanf("%s", str1);
        scanf("%s", str2);
        for(i = 0; i < strlen(str1); i++){
            if(str1[i] == str2[0]){
                f = 0;
                for(j = 0; j < strlen(str2); j++){
                    if(str1[i+j] == str2[j]){
                        f = 1;
                    }
                    else{
                        f = 0;
                        break;
                    }
                }
                if(f == 1){
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}
