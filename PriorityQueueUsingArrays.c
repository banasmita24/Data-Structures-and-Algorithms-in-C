#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int queue[SIZE], front=-1, rear=-1, choice, item;

void enqueue();
void dequeue();
void display();

int is_empty()
{
    return front==-1;
}
int is_full()
{
    return rear==SIZE-1;
}

int main()
{
    do
    {
        printf("\n1-Enqueue \n2-Dequeue \n3-Display \n4-EXIT \nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(1);
            default: printf("\nINVALID CHOICE\n");
        }
    }while(choice != 0);
    return 0;
}

void enqueue()
{
    if(is_full())
    {
        printf("\nQueue Overflow\n");
        return;
    }
    printf("\nEnter the item to enqueue: ");
    scanf("%d",&item);
    if(is_empty())
    {
        front=0;
        rear=0;
        queue[rear]=item;
    }
    else
    {
        int i;
        for(i=rear; i>=front && queue[i]>item; i--)
        {
            queue[i+1]=queue[i];
        }
        queue[i+1]=item;
        rear++;
    }
    printf("\nItem Enqueued: %d\n",item);
    printf("\nQueue: ");
    display();
}

void dequeue()
{
    if(is_empty())
    {
        printf("\nQueue Underflow\n");
        return;
    }
    item=queue[front];
    front++;
    if(front>rear)
    {
        front=rear=-1;
    }
    printf("\nDequeued: %d\n", item);
    printf("\nQueue: ");
    display();
}

void display()
{
    if(is_empty())
    {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nQueue Elements are: ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\nFront: %d\t Rear: %d\n",front,rear);
}

