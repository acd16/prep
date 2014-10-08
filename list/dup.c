#include "list.h"

node * addNode(node * head, int data){
    node * new = malloc(sizeof(node));
    new->val = data;
    new->next = NULL;
    if (head == NULL){
        return new;
    }
    node * track = head;
    while(track->next)
        track = track->next;
    track->next = new;
    return head;
}

void printList(node * head){
    printf("printing\n");
    while(head){
        printf("%d\n", head->val);
        head = head-> next;
    }
}

node *delDup(node * head){
node *track = head;
node *fast = NULL, *prev = NULL, *check = NULL;
int data=0;
while (track){
    data = track->val;
    fast = track->next;
    prev = track;
    while(fast){
        if(fast->val == data){
            prev->next = fast->next;
            check = fast;
            fast = fast->next;
            free(check);
        }
        else{
            prev = prev->next;
            fast = fast->next;
        }
    }
    track = track->next;
}
return head;
}

int main(){
    node * head = NULL;
    head = addNode(head, 5);
    head = addNode(head, 5);
    head = addNode(head, 5);
    head = addNode(head, 5);
    head = addNode(head, 5);
    head = addNode(head, 6);
    printList(head);
    delDup(head);
    printList(head);
}

