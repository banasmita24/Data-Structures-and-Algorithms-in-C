#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int enqueue();
int dequeue();
int display();

struct queue
{
    int front;
    int rear;
    int *q;
};

int choice,item;

int main()
{
    struct queue Q;
    Q.front=-1;
    Q.rear=-1;
    Q.q=(int*)malloc(10*sizeof(int));
    for(;;)
    {
        printf("1-Enqueue \n2-Dequeue \n3-Display \n4-EXIT \nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:enqueue(&Q);
                   break;
            case 2:dequeue(&Q);
                   break;
            case 3:display(&Q);
                   break;
            case 4:return 0;
            default: printf("\nINVALID CHOICE\n");
        }
    }
}

int enqueue(struct queue *Q)
{
    printf("Enter the element to enqueue: ");
    scanf("%d",&item);
    if(Q->rear==SIZE-1)
    {
        printf("\nQueue Overflow\n");
    }
    else
    {
        if(Q->front==-1)
       {
            Q->front++;
       }
       Q->rear++;
       *(Q->q+Q->rear)=item;
}
int dequeue(struct queue *Q)
{
    if (Q->front == -1)
    {
        printf("\nQueue Underflow\n");
        return 0;
    }

    item=*(Q->q+Q->front);
    Q->front++;

    if(Q->front>Q->rear)
    {
        Q->front=Q->rear=-1;
    }
    printf("\nDequeued Element is: %d\n",item);
}

int display(struct queue *Q)
{
    if(Q->front==-1)
    {
        printf("\nQueue is Empty\n");
    }
    printf("\nQueue Elements are: ");
    for(int i=Q->front;i<Q->rear;i++)
    {
        printf("%d ",Q->q[i]);
    }
    printf("\n");
}

