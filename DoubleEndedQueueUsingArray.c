#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int deque[SIZE], front=-1, rear=-1, choice, item;

void insert_front();
void insert_rear();
void delete_front();
void delete_rear();
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
        printf("\n1-Insert at Front \n2-Insert at Rear \n3-Delete from Front \n4-Delete from Rear \n5-Display \n6-EXIT \nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert_front();
                    break;
            case 2: insert_rear();
                    break;
            case 3: delete_front();
                    break;
            case 4: delete_rear();
                    break;
            case 5: display();
                    break;
            case 6: exit(1);
            default: printf("\nINVALID CHOICE");
        }
    }
    while(choice != 0);
    return 0;
}

void insert_front()
{
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&item);

    if(is_full())
    {
        printf("\nDeque Overflow\n");
        return;
    }
    if(is_empty())
    {
        front=0;
        rear=0;
    }
    else
    {
        for(int i=rear;i>=0;i--)
        {
            deque[i+1]=deque[i];
        }
        rear++;
    }
    deque[front]=item;
    printf("\nInserted element at front end is: %d\n", item);
    display();
}

void insert_rear()
{
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&item);

    if(is_full())
    {
        printf("\nDeque Overflow\n");
        return;
    }
    else if(is_empty())
    {
        front=0;
        rear=0;
    }
    else
    {
        rear++;
    }
    deque[rear]=item;
    printf("\nInserted element at rear end is: %d\n", item);
    display();
}

void delete_front()
{
    if(is_empty())
    {
        printf("\nDeque Underflow\n");
        return;
    }
    item=deque[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front++;
    }
    printf("\nDeleted from front: %d\n", item);
    display();
}

void delete_rear()
{
    if(is_empty())
    {
        printf("\nDeque Underflow\n");
        return;
    }
    item=deque[rear];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        rear--;
    }
    printf("\nDeleted from rear: %d\n", item);
    display();
}

void display()
{
    if(is_empty())
    {
        printf("\nDeque is Empty\n");
        return;
    }
    printf("\nDequeue Elements: ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d\t",deque[i]);
    }
    printf("\nFront: %d \tRear: %d\n",front,rear);
}

