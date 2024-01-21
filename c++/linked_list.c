#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void traverseList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        printf("Menu:\n");
        printf("1. Create a linked list\n");
        printf("2. Insert a value\n");
        printf("3. Traverse the linked list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to create the linked list: ");
                scanf("%d", &value);
                head = createNode(value);
                break;
            case 2:
                if (head == NULL) {
                    printf("The linked list is empty. Create a linked list first.\n");
                } else {
                    printf("Enter a value to insert: ");
                    scanf("%d",&value);
                    insertNode(&head,value);
                }
                break;
            case 3:
                if (head == NULL) {
                    printf("The linked list is empty.\n");
                } else {
                    printf("Linked list contents: ");
                    traverseList(head);
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

