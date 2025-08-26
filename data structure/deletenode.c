#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Traverse and print
void linkedlist(struct Node *ptr) {
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Delete at beginning
struct Node* deleteatbeginning(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete at end
struct Node* deleteatend(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL) { // Only one node
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL) { // stop at second last
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete at given position (1-based index)
struct Node* deleteatposition(struct Node *head, int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (pos == 1) { // delete first node
        return deleteatbeginning(head);
    }
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return head;
    }
    struct Node *todelete = temp->next;
    temp->next = temp->next->next;
    free(todelete);
    return head;
}
int main() {
    struct Node *head = NULL;
    struct Node *n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node*)malloc(sizeof(struct Node));

    // Create a sample list: 10 -> 20 -> 30
    n1->data = 10; n1->next = n2;
    n2->data = 20; n2->next = n3;
    n3->data = 30; n3->next = NULL;
    head = n1;

    printf("Original list: ");
    linkedlist(head);

    head = deleteatbeginning(head);
    printf("After deleting at beginning: ");
    linkedlist(head);

    head = deleteatend(head);
    printf("After deleting at end: ");
    linkedlist(head);

    // Adding back some nodes for demo
    struct Node *n4 = (struct Node*)malloc(sizeof(struct Node));
    n4->data = 40; n4->next = head;
    head = n4; // 40 -> 20

    struct Node *n5 = (struct Node*)malloc(sizeof(struct Node));
    n5->data = 50; n5->next = NULL;
    head->next->next = n5; // 40 -> 20 -> 50

    printf("Before deleting at position 2: ");
    linkedlist(head);

    head = deleteatposition(head, 2);
    printf("After deleting at position 2: ");
    linkedlist(head);

    return 0;
}


