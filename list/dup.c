#include "list.h"
node * addNode(node * head, int data, int cycle){
    node * new = malloc(sizeof(node)), *link;
    int i=0;
    new->val = data;
    new->next = NULL;
    if (head == NULL){
        return new;
    }
    node * track = head;
    while(track->next){
        track = track->next;
        if(cycle && i==2){
            link = track;
        }
        i++;
    }
    if(cycle)
        new->next=link;
    track->next = new;
    return head;
}

void printList(node * head){
    printf("printing\n");
    while(head){
        printf("%d %p -> ", head->val, head);
        //printf("%d->", head->val);
        head = head-> next;
    }
    printf("\n");
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

void recrev(node ** head){
    node * first, *next;
    if (*head == NULL)
        return;
    else{
        first = *head;
        next = (*head)->next;
        if(next == NULL)
            return;
        recrev(&next);
        first->next->next = first;
        first->next = NULL;
        *head = next;
    }
}

node * rev(node *head){
    node * current, *prev, *next;
    prev = NULL;
    current = head;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

node * revn(node * head, int n){
    node * current=NULL, *prev=NULL, *fast=NULL;
    current = head;
    int k = 0;
    while(current != NULL && k<n){
        fast = current->next;
        current -> next = prev;
        prev = current;
        current = fast;
        k++;
    }
    if(fast != NULL)
        head->next=revn(fast, n);
    return prev;
}

node *revaltn(node * head, int n){
    node * current=NULL, *prev=NULL, *fast=NULL;
    current = head;
    int k=0;
    while(current != NULL && k<n){
        fast = current->next;
        current -> next = prev;
        prev = current;
        current = fast;
        k++;
    }
    if(head != NULL){
        head->next = current;
    }
    k=0;
    while(current != NULL && k<n-1){
        current = current -> next;
        k++;
    }
    if(current != NULL)
        current->next = revaltn(current->next, n);

    return prev;
}

int loopCheck(node * head){
    node * slow, *fast;
    slow = fast = head;
    if(head != NULL)
        slow = head->next;
    if(head->next != NULL)
        fast = head->next->next;
    while(slow != NULL && fast->next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(fast == slow){
            printf("loop exits\n");
            return 1;
        }
    }
    return 0;
}

int fromLast(node *head, int n){
    node * slow, *fast;
    int k = 1;
    if(head == NULL)
        return -1;
    fast = slow = head;
    while(fast != NULL && k<=n){
        fast = fast->next;
        k++;
    }
    if(k<n)
        return -1;
    else{
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        printf("nth ele is %d\n", slow->val);
        return 0;
    }
    return -1;
}

int isPalin(node **left, node * right){
    int out=0;
    if(right == NULL)
        return 1;
    out = isPalin(left, right->next);
    if(out)
        return 1;
    if((*left)->val != right->val)
        return 1;
    *left = (*left)->next;
        return 0;
}

void isPalinHelper(node * head){
    if(!isPalin(&head, head)){
        printf("it is a palindrome\n");
    }
}

int main(){
    node * head = NULL;
    head = addNode(head, 1, 0);
    head = addNode(head, 2, 0);
    head = addNode(head, 3, 0);
    head = addNode(head, 4, 0);
    head = addNode(head, 3, 0);
    head = addNode(head, 2, 0);
    head = addNode(head, 1, 0);
    //head = addNode(head, 8, 0);
    //printList(head);
    //delDup(head);
    //recrev(&head);
    //head = revaltn(head, 3);
    //printf("%d\n", loopCheck(head));
    //fromLast(head, 2);
    isPalinHelper(head);
    //printList(head);
}

