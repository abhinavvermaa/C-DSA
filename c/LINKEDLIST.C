#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void prnt(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element :  %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct node * insertatfirst(struct node*head, int data){
    struct node * ptr = (struct node *)malloc(sizeof (struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct node * insertatindex(struct node*head, int data, int index){
    struct node * ptr = (struct node *)malloc(sizeof (struct node));
    struct node * p = head;
    int i=0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next =ptr;
}
struct node * insertatend(struct node*head, int data){
    struct node * ptr = (struct node *)malloc(sizeof (struct node));
    ptr->data = data;
    struct node * p = head;
    while(p->next !=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;

}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 39;
    third->next = NULL;

    prnt(head);
    head = insertatend(head, 56);
    prnt(head);
    return 0;
}
