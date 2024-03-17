#include <stdio.h>
#include <string.h>

#define SIZE 5

int top = -1;
int choice;

struct books
{
    char sub[20];
    int qty;
};

struct books mybook[SIZE];

void push()
{
    if (top == SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }

    top++;
    printf("Enter a subject to be pushed: ");
    scanf("%s",mybook[top].sub);
    printf("Enter the quantity to be pushed: ");
    scanf("%d", &mybook[top].qty);
    getchar();
}

void pop()
{
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }

    printf("Popped subject: %s, Quantity: %d\n", mybook[top].sub, mybook[top].qty);
    top--;
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents:\n");
    for (int i = top; i >= 0; i--)
    {
        printf("Subject: %s, Quantity: %d\n", mybook[i].sub, mybook[i].qty);
    }
}

int main()
{
    for(;;)
    {
        printf("Enter your choice\n1 -> Push\n2 -> Pop\n3 -> Display\n4 -> Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:push();
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            case 4:return 0;
            default:printf("Invalid choice\n");
                    return 0;
        }
    }

    return 0;
}
