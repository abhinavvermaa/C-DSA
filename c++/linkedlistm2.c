#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createlist(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory allocation failed");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
void trav(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    struct node *head = NULL;
    int choice, value;
    // printf("enter the value -");
    // scanf("%d", &value);
    // head = createlist(value);
    // trav(head);
    do
    {
        printf("Menu:\n");
        printf("1. Create a linked list\n");
        printf("2. Insert a value\n");
        printf("3. Traverse the linked list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a value to create the linked list: ");
            scanf("%d", &value);
            head = createlist(value);
            break;
        case 2:
        if (head == NULL)
        {
            printf("The linked list is empty. Create a linked list first.\n");
        }
        else
        {
            printf("Enter a value to insert: ");
            scanf("%d", &value);
            insertatend(head, value);
        }
        break;
    case 3:
        if (head == NULL)
        {
            printf("The linked list is empty.\n");
        }
        else
        {
            printf("Linked list contents: ");
            trav(head);
        }
        break;
    case 4:
        printf("Exiting the program.\n");
        break;
    default:
        printf("Invalid choice. Please try again.\n");
    }
}
while (choice != 4);
}