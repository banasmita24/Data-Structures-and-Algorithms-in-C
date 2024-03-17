#include<stdio.h>
#include<stdlib.h>

struct book
{
    char title[100];
    char author[50];
    float price;
    int edition;
};

struct node
{
    struct book data;
    struct node *next;
};

struct node *start = NULL;

struct node *getnode()
{
    return ((struct node *)malloc(sizeof(struct node)));
};

void create()
{
    start = getnode();
    struct node *p, *q;
    p = getnode();
    q = getnode();
    printf("\nEnter Book Title: ");
    scanf(" %s", start->data.title);
    printf("Enter Author Name: ");
    gets(start->data.author);
    printf("Enter Price: ");
    scanf("%f", &start->data.price);
    printf("Enter Edition: ");
    scanf("%d", &start->data.edition);
    start->next = NULL;
    p = start;
    while(1)
    {
        printf("\n1-Continue and 0-Exit: ");
        int ch;
        scanf("%d", &ch);
        if(ch == 1)
        {
            printf("\nEnter Book Title: ");
            gets(q->data.title);
//            printf("Enter Author Name: ");
//            gets(q->data.author);
            printf("Enter Price: ");
            scanf("%f", &q->data.price);
            printf("Enter Edition: ");
            scanf("%d", &q->data.edition);
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
    struct node *p;
    p = getnode();
    printf("\nEnter Book Title: ");
    gets(p->data.title);
//    printf("Enter Author Name: ");
//    gets(p->data.author);
    printf("Enter Price: ");
    scanf("%f", &p->data.price);
    printf("Enter Edition: ");
    scanf("%d", &p->data.edition);
    p->next = start;
    start = p;
}

void insertEnd()
{
    struct node *p, *q;
    q = getnode();
    printf("\nEnter Book Title: ");
    gets(q->data.title);
//    printf("Enter Author Name: ");
//    gets(q->data.author);
    printf("Enter Price: ");
    scanf("%f", &q->data.price);
    printf("Enter Edition: ");
    scanf("%d", &q->data.edition);
    q->next = NULL;
    p = start;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void insertPos()
{
    int pos;
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
    for (int i = 1; i < pos - 1 && p != NULL; i++)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("Position %d doesn't exist\n", pos);
        return;
    }
    q = getnode();
    printf("\nEnter Book Title: ");
    gets(q->data.title);
//    printf("Enter Author Name: ");
//    gets(q->data.author);
    printf("Enter Price: ");
    scanf("%f", &q->data.price);
    printf("Enter Edition: ");
    scanf("%d", &q->data.edition);
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

void deletePos()
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
    struct node *p;
    p = start;
    if (p == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    while (p != NULL)
    {
        printf("%s", p->data.title);
//        printf("\n%s", p->data.author);
        printf("\n%f", p->data.price);
        printf("\n%d", p->data.edition);
        printf("\n---------------------------------\n");
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    do
    {
        printf("\n1-Enter details of the books");
        printf("\n2-Insert book at the beginning");
        printf("\n3-Insert book at the end");
        printf("\n4-Insert book at the Nth position");
        printf("\n5-Delete book at the beginning");
        printf("\n6-Delete book at the end");
        printf("\n7-Delete book at the Nth position");
        printf("\n8-Display");
        printf("\n9-EXIT");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: create();
                    break;
            case 2: insertBeg();
                    break;
            case 3: insertEnd();
                    break;
            case 4: insertPos();
                    break;
            case 5: deleteBeg();
                    break;
            case 6: deleteEnd();
                    break;
            case 7: deletePos();
                    break;
            case 8: display();
                    break;
            case 9: exit(1);
            default: printf("\nINVALID CHOICE\n");
        }
    }while(choice != 0);
}
