#include <stdio.h>
#include <stdlib.h>
//involves creation and traversal in a ll

struct Node{
    int data;
    struct Node *next;
};
void linkedlist(struct Node *ptr){
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    }

}
struct Node* insertatend(struct Node *head,int value){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->value=
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    head->data=7;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=15;
    third->next=NULL;
    linkedlist(head);
    return 0;
}
