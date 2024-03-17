#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front=-1,rear=-1;
void enqueue()
{
    int x;
    printf("\nEnter the data: ");
    scanf("%d",&x);
    if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=x;
        printf("\nInserted successfully\n");
    }
    else if((rear+1)%N==front)
        printf("\nQueue is full\n");
    else if(rear==N-1)
    {
        rear=0;
        queue[rear]=x;
        printf("\nInserted successfully\n");
    }
    else
        {
        rear=(rear+1)%N;
        queue[rear]=x;
        printf("\nInserted successfully\n");
    }
}
void dequeue()
{
    if(front==-1&&rear==-1)
        printf("\nQueue is empty\n");
    else if(front==rear)
    {
        printf("\n%d deleted successfully",queue[front]);
        front=-1;
        rear=-1;
    }
    else if(front==N-1)
    front=0;
    else
    {
        printf("\n%d deleted successfully",queue[front]);
        front=(front+1)%N;
    }
}
void display()
{
    int i=front;
    if(front==-1&&rear==-1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
     printf("\nThe elements in the Queue are: \n");
    {
        while(i!=rear)
        {
            printf("%d\t",queue[i]);
            i=(i+1)%N;
        }
        printf("%d",queue[rear]);
    }
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n\n\t\tCIRCULAR QUEUE OPERATIONS\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
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
            default:printf("\nInvalid choice\n");
        }
    }
}
