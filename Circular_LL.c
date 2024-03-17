#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *getnode()
{
    return ((struct node *)malloc(sizeof(struct node)));
};

void createList()
{
    struct node *p, *q;
    start = getnode();
    q = getnode();
    printf("\nEnter Data: ");
    scanf("%d", &start->data);
    start->next = start;
    p = start;
    while(1)
    {
        printf("\n1 - Continue and 0 - EXIT : ");
        int ch;
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("\nEnter Data: ");
            scanf("%d", &q->data);
            q->next = start;
            p->next = q;
            p = q;
        }
        else
            break;
    }
}

void insertBeg()
{
    struct node *p, *q;
    p = start;
    q = getnode();
    printf("\nEnter the element to insert in the beginning: ");
    scanf("%d", &q->data);
    q->next = p;
    if (p == NULL)
    {
        // If list is empty, make q point to itself
        q->next = q;
        start = q;
        return;
    }
    while (p->next != start)
    {
        p = p->next;
    }
    p->next = q;
    start = q;
}


void insertEnd()
{
    struct node *q, *p;
    q = getnode();
    printf("\nEnter the element to insert at the End: ");
    scanf("%d", &q->data);
    if (start == NULL)
    {
        q->next = q;
        start = q;
        return;
    }
    p = start;
    while(p->next != start)
    {
        p = p->next;
    }
    p->next = q;
    q->next = start;
}

void insertNPos()
{
    struct node *q, *p;
    q = getnode();
    if (start == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    int pos;
    printf("\nEnter your position to insert: ");
    scanf("%d", &pos);
    if (pos<1)
    {
        printf("\nInvalid Position\n");
        return;
    }
    if (pos == 1)
    {
        insertBeg();
        return;
    }
    p = start;
    for (int i=1; i<pos-1 && p->next != start; i++)
    {
        p = p->next;
    }
    if (p->next == start)
    {
        printf("\nPosition %d does not exist\n", pos);
        return;
    }
    printf("\nEnter the element to insert: ");
    scanf("%d", &q->data);
    q->next = p->next;
    p->next = q;
}

void deleteBeg()
{
    struct node *p, *q;
    if (start == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    if (start->next == start)
    {
        free(start);
        start = NULL; //If there is only one node in the list
        return;
    }
    p = start;
    while (p->next != start)
    {
        p = p->next;
    }
    q = start;
    start = start->next;
    p->next = start;
    free(q);
}

void deleteEnd()
{
    struct node *p, *q;
    if (start == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    if (start->next == start)
    {
        free(start);
        start = NULL;
        return;
    }
    p = start;
    while (p->next != start)
    {
        q = p;
        p = p->next;
    }
    q->next = start;
    free(p);
}

void deleteNPos()
{
    struct node *p, *q;
    if (start == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    int pos;
    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);
    if (pos<1)
    {
        printf("\nInvalid Position\n");
        return;
    }
    if (pos == 1)
    {
        deleteBeg();
        return;
    }
    p = start;
    q = NULL;
    for (int i=1; i<pos && p->next != start; i++)
    {
        q = p;
        p = p->next;
    }
    if (p->next == start)
    {
        printf("\nPosition %d does not exist\n", pos);
        return;
    }
    q->next = p->next;
    free(p);
}

void display()
{
    struct node *p;
    p = start;
    if (p == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    printf("\nList Elements: ");
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != start);
    printf("\n");
}


int main()
{
    int choice;
    do
    {
        printf("\n1 - Create List\n");
        printf("2 - Insert at the beginning\n");
        printf("3 - Insert at the end\n");
        printf("4 - Insert at the Nth position\n");
        printf("5 - Delete at the beginning\n");
        printf("6 - Delete at the end\n");
        printf("7 - Delete at the Nth position\n");
        printf("8 - Display\n");
        printf("9 - EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: createList();
                    break;
            case 2: insertBeg();
                    break;
            case 3: insertEnd();
                    break;
            case 4: insertNPos();
                    break;
            case 5: deleteBeg();
                    break;
            case 6: deleteEnd();
                    break;
            case 7: deleteNPos();
                    break;
            case 8: display();
                    break;
            case 9: exit(1);
            default: printf("\nINVALID CHOICE\n");
        }
    }while(choice != 0);
    return 0;
}

