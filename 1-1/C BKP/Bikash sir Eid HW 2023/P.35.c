#include<stdio.h>
#include<math.h>

int main(){
    int t,Xc,Yc,r,X,Y,str;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &Xc, &Yc);
        scanf("%d", &r);
        scanf("%d%d", &X,&Y);
        str = sqrt(((X-Xc)*(X-Xc)) + ((Y-Yc)*(Y-Yc)));

        if(str > r){
            printf("The point is not inside the circle\n");
        }
        else{
            printf("The point is inside the circle\n");
        }
    }
    return 0;
}
