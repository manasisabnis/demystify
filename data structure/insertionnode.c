#include <stdio.h>
#include <stdlib.h>

// Node definition
typedef struct Node {
    int data;
    struct Node *link;
} Node;

// Function to create a new node
Node *create_node(int value) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data = value;
    temp->link = NULL;
    return temp;
}

// Insert at the front
void insert_rear(int value, Node **start) {
    Node *temp = create_node(value);
    if (*start == NULL) {
        *start = temp;
        return;
    }
    Node *curr = *start;
    while (curr->link != NULL) {
        curr = curr->link;
    }
    curr->link = temp;
}


// Delete front node
void delete_front(Node **start) {
    if (*start == NULL) {
        printf("The list is empty\n");
        return;
    }
    Node *temp = *start;
    *start = (*start)->link;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display list
void display(Node *start) {
    if (start == NULL) {
        printf("The list is empty\n");
        return;
    }
    printf("The elements in the list are:\n");
    while (start != NULL) {
        printf("%d\t", start->data);
        start = start->link;
    }
    printf("\n");
}

// Search for a value
int search(int value, Node *start) {
    int position = 1;
    while (start != NULL) {
        if (start->data == value) {
            return position;
        }
        start = start->link;
        position++;
    }
    return -1; // Not found
}

// Concatenate two lists
void concatenate(Node **list1, Node *list2) {
    if (*list1 == NULL) {
        *list1 = list2;
        return;
    }
    Node *temp = *list1;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = list2;
}

// Reverse a list
void reverse(Node **start) {
    Node *prev = NULL, *curr = *start, *next = NULL;
    while (curr != NULL) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    *start = prev;
}

// Merge two sorted lists
Node *merge_sorted(Node *list1, Node *list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Node *result = NULL;
    if (list1->data <= list2->data) {
        result = list1;
        result->link = merge_sorted(list1->link, list2);
    } else {
        result = list2;
        result->link = merge_sorted(list1, list2->link);
    }
    return result;
}

// Main function
int main() {
    int value, choice;
    Node *start = NULL; // List 1
    Node *start2 = NULL; // List 2 (for concat/merge)

    while (1) {
        printf("\nEnter choice:\n");
        printf("1) Insert front (List 1)\n");
        printf("2) Delete front (List 1)\n");
        printf("3) Display (List 1)\n");
        printf("4) Search (List 1)\n");
        printf("5) Reverse (List 1)\n");
        printf("6) Insert front (List 2)\n");
        printf("7) Display (List 2)\n");
        printf("8) Concatenate List 2 to List 1\n");
        printf("9) Merge List 1 and List 2 (Sorted)\n");
        printf("10) Exit\n");
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
                printf("Enter the value to search: ");
                scanf("%d", &value);
                {
                    int pos = search(value, start);
                    if (pos != -1)
                        printf("Element %d found at position %d\n", value, pos);
                    else
                        printf("Element %d not found\n", value);
                }
                break;

            case 5:
                reverse(&start);
                printf("List 1 reversed.\n");
                break;

            case 6:
                printf("Enter the value: ");
                scanf("%d", &value);
                insert_rear(value, &start2);
                break;

            case 7:
                display(start2);
                break;

            case 8:
                concatenate(&start, start2);
                start2 = NULL;
                display(start);
                printf("Lists concatenated.\n");
                break;

            case 9:
                start = merge_sorted(start, start2);
                start2 = NULL;
                printf("Lists merged into sorted order.\n");
                break;

            case 10:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}