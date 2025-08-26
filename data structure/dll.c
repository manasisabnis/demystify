#include <stdio.h>
#include <stdlib.h>

// Node definition for doubly linked list
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Function to create a new node
Node *create_node(int value) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

// Insert at the rear
void insert_rear(int value, Node **start) {
    Node *temp = create_node(value);
    if (*start == NULL) {
        *start = temp;
        return;
    }
    Node *curr = *start;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
}

// Delete front node
void delete_front(Node **start) {
    if (*start == NULL) {
        printf("The list is empty\n");
        return;
    }
    Node *temp = *start;
    *start = temp->next;
    if (*start != NULL)
        (*start)->prev = NULL;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display list forward
void display(Node *start) {
    if (start == NULL) {
        printf("The list is empty\n");
        return;
    }
    printf("The elements in the list are:\n");
    while (start != NULL) {
        printf("%d\t", start->data);
        start = start->next;
    }
    printf("\n");
}
// Reverse the list
void reverse(Node **start) {// very important
    Node *curr = *start, *temp = NULL;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
        *start = temp->prev;
}

int main() {
    int value, choice;
    Node *start = NULL;
    Node *start2 = NULL;

    while (1) {
        printf("\nEnter choice:\n");
        printf("1) Insert rear (List 1)\n");
        printf("2) Delete front (List 1)\n");
        printf("3) Display (List 1)\n");
   
        printf("4) Reverse (List 1)\n");
               printf("5) Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                insert_rear(value, &start);
                break;

            case 2:
                delete_front(&start);
                break;

            case 3:
                display(start);
                break;

     

            case 4:
                reverse(&start);
                printf("List 1 reversed.\n");
                display(start);
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}