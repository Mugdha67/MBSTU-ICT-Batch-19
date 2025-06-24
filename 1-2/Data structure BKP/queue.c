#include <stdio.h>
#include<stdlib.h>
#define MAX 3
void insert();
void delete();
void show();
int queue_array[MAX];
int rear = - 1;
int front = - 1;
main()
{
    int choice;
    printf("You have %d rooms\n\n",MAX);
    printf("At first rear value :%d \n",rear);
    printf("At first front value :%d \n\n",front);

    while (1)
    {
        printf("1.Insert \n");
        printf("2.Delete \n");
        printf("3.Show \n");
        printf("4.Exit \n");
        printf("Select any from 1 to 4: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(1);
        default:
            printf("You have selected wrong key\n");
        }
    }
}

void insert()
{
    int add_item;
    if (rear == MAX - 1)
        printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
            front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;

        printf("now rear value :%d \n",rear);
        printf("now front value :%d \n",front);
    }
}

void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }

    printf("now rear value :%d \n",rear);
    printf("now front value :%d \n",front);
}

void show()
{
    int i;



    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Element/s in queue: ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}
