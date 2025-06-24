#include<stdio.h>
void push();
void pop();
int a[100],n,i,c;
int main()
{

    printf("Enter the number of element:");
    scanf("%d",&n);
    printf("Enter %d values below:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(1)
    {
        printf("Enter 1 to insert data or enter 2 to delete data:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            {
                push();
            }
        case 2:
            {
                pop();
            }
        }
    }
    return 0;
}
