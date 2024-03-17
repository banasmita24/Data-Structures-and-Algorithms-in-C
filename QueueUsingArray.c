#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void enqueue();
void dequeue();
void display();

int choice,item,front=-1,rear=-1,queue[SIZE];

int main()
{
    do
    {
        printf("\n1-ENQUEUE \n2-DEQUEUE \n3-DISPLAY \n4-EXIT \nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:enqueue();
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            case 4:exit(1);
                   break;
            default: printf("\nINVALID CHOICE\n");
                     return 0;
        }
    }
    while(choice!=0);
    return 0;
}

void enqueue()
{
    if(rear==SIZE-1)
    {
        printf("\nQueue Overflow\n");
    }
    else
    {
        if(rear==-1 && front==-1)
        {
            front=0;
            rear=0;
        }
        else
        {
            rear++;
        }
        printf("\nEnter the element to be Enqueued: ");
        scanf("%d",&item);
        queue[rear]=item;
        printf("\n%d is inserted successfully\n",item);
    }
}

void dequeue()
{
    if(front==-1||front>rear)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        item=queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
             front++;
        }
        printf("\nDequeued item: %d\n", item);
    }
}

void display()
{
    if(rear==-1)
    {
        printf("\nQueue is empty\n");
    }
    printf("\nQueue elements: ");
    for (int i=front;i<=rear;i++)
    {
        printf("%d\t",queue[i]);
    }
    printf("\n");
}










