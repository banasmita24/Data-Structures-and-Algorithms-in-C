#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *getnode()
{
    return ((struct node *)malloc(sizeof(struct node)));
}

void createList()
{
    int ch;
    struct node *p, *q;
    start = getnode();
    p = getnode();
    q = getnode();
    printf("\nEnter data: ");
    scanf("%d", &start->data);
    start->next = NULL;
    p = start;
    while(1)
    {
        printf("\nPress 1-continue and 0-exit: ");
        scanf("%d", &ch);
        if(ch==1)
        {
            printf("\nEnter data: ");
            scanf("%d", &q->data);
            q->next = NULL;
            p->next = q;
            p = q;
        }
        else
            break;
    }
}

void insertBeg()
{
    int ele;
    printf("\nEnter the element to insert at the beginning: ");
    scanf("%d", &ele);
    struct node *p;
    p = getnode();
    p->data = ele;
    p->next = start;
    start = p;
}

void insertEnd()
{
    int ele;
    printf("\nEnter the element to insert at the end: ");
    scanf("%d", &ele);
    struct node *p, *q;
    q = getnode();
    q->data = ele;
    q->next = NULL;
    p = start;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void insertNPos()
{
    int pos, ele, i;
    struct node *p, *q;
    printf("\nEnter the position to insert: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    p = start;
    if (pos == 1)
    {
        insertBeg();
        return;
    }
    for (i = 1; i < pos - 1 && p != NULL; i++)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("Position %d doesn't exist\n", pos);
        return;
    }
    q = getnode();
    printf("\nEnter the element to insert: ");
    scanf("%d", &q->data);
    q->next = p->next;
    p->next = q;
}

void deleteBeg() {
    struct node *temp;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = start;
    start = start->next;
    free(temp);
}

void deleteEnd()
{
    struct node *p, *prev;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (start->next == NULL)
    {
        free(start);
        start = NULL;
        return;
    }
    p = start;
    while (p->next != NULL)
    {
        prev = p;
        p = p->next;
    }
    prev->next = NULL;
    free(p);
}

void deleteNPos()
{
    int pos, i;
    struct node *p, *prev;
    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1)
    {
        deleteBeg();
        return;
    }
    p = start;
    prev = NULL;
    for (i = 1; i < pos && p != NULL; i++)
    {
        prev = p;
        p = p->next;
    }
    if (p == NULL)
    {
        printf("Position %d doesn't exist\n", pos);
        return;
    }
    prev->next = p->next;
    free(p);
}

void display()
{
    struct node *p = start;
    if (p == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    do
    {
        printf("\n1-Create List");
        printf("\n2-Insert element at the begining");
        printf("\n3-Insert element at the end");
        printf("\n4-Insert element at the nth position");
        printf("\n5-Delete element at the begining");
        printf("\n6-Delete element at the end");
        printf("\n7-Delete element at the nth position");
        printf("\n8-Display List elements");
        printf("\n9-Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createList();
                break;
            case 2:
                insertBeg();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                insertNPos();
                break;
            case 5:
                deleteBeg();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                deleteNPos();
                break;
            case 8:
                display();
                break;
            case 9:
                exit(1);
            default:
                printf("\nINVALID STATEMENT\n");
        }
    } while (choice != 0);

    return 0;
}
