#include<stdio.h>
#include<string.h>

int main(){
    int t;
    char str[1001], reverse[1001], main[1001];
    scanf("%d", &t);
    while(t--){
        scanf("%s", &str);
        strcpy(main,str);
        strcpy(reverse,strrev(str));

        if(strcmp(main,reverse) == 0){
            printf("Yes! It is a palindrome!\n");
        }
        else{
            printf("Sorry! It is not a palindrome!\n");
        }
    }
    return 0;
}
