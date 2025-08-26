#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *tail = NULL;

// 1) Insert at beginning
void insertAtBeginning(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;

    if (head == NULL) {
        head = tail = newnode;
    } else {
        head->prev = newnode;
        head = newnode;
    }
}

// 1) Insert at end
void insertAtEnd(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = tail;

    if (tail == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

// 2) Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    if (head == tail) { // only 1 node
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}

// 2) Delete from end
void deleteFromEnd() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = tail;
    if (head == tail) { // only 1 node
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    printf("Deleted %d from end\n", temp->data);
    free(temp);
}

// 3) Display
void display() {
    struct node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 4) Search
void search(int value) {
    struct node *temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Found %d at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d not found\n", value);
}

// 5) Concatenate another list
void concatenate(struct node *head2) {
    if (head == NULL) {
        head = head2;
        return;
    }
    if (head2 == NULL) return;

    tail->next = head2;
    head2->prev = tail;

    // move tail pointer to end of new list
    struct node *temp = head2;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    tail = temp;
}

// 6) Reverse list
void reverse() {
    struct node *current = head, *temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  // move backwards
    }
    if (temp != NULL) {
        head = temp->prev;
    }
}

// 7) Insert at a specified position (1-based index)
void insertAtPosition(int value, int pos) {
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    struct node *temp = head;
    for (int i = 1; temp != NULL && i < pos-1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;

    if (newnode->next == NULL) // if inserted at end
        tail = newnode;
}

// Driver code
int main() {
    int choice, value, pos;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Delete from Beginning\n4. Delete from End\n");
        printf("5. Display\n6. Search\n7. Reverse\n8. Insert at Position\n9. Concatenate another list\n10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 7:
                reverse();
                printf("List reversed.\n");
                break;
            case 8:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(value, pos);
                break;
            case 9: {
                // Create another list for demo
                struct node *head2 = NULL, *tail2 = NULL;
                struct node *n1 = (struct node*)malloc(sizeof(struct node));
                n1->data = 100; n1->next = NULL; n1->prev = NULL;
                head2 = tail2 = n1;

                struct node *n2 = (struct node*)malloc(sizeof(struct node));
                n2->data = 200; n2->next = NULL; n2->prev = tail2;
                tail2->next = n2;
                tail2 = n2;

                concatenate(head2);
                printf("Concatenated second list.\n");
                break;
            }
            case 10:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
