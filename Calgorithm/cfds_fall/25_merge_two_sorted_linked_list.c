#include<stdio.h>
#include<stdlib.h>

/* Linked list node structure */

struct Node
{
    int data;
    struct Node* next;
};


struct Node* mergeTwoLists(struct Node* a, struct Node* b){
    struct Node h ;
    struct Node* head = &h;
    if (a == NULL && b == NULL)
        return NULL;
    while (a && b){
        if(a->data < b->data){
            head->next = a;
            a = a->next;
            head = head->next;
        }
        else{
            head->next = b;
            b = b->next;
            head = head->next;
        }
    }
    if (a)
        head->next = a;
    if (b)
        head->next = b;

    head = &h;
    return head->next;
}
    // DO NOT MODIFY BELOW

/* Function to create a new node */
struct Node * createNode(int x){
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}
typedef struct listType SLList;
struct listType{
    struct Node *first;
    int size;
};

void addFirst(SLList *LL, int x);

int main(int argc, char* argv[]){ //./25_merge_two_sorted_linked_list 1 3 5 7 2 4 6 8
    SLList list_a = {NULL, 0};
    SLList list_b = {NULL, 0};
    for(int i = 0; i < (argc-1)/2; i++)
        addFirst(&list_a, atoi(argv[(argc-1)/2-i])); 

    for(int i = 0; i < argc/2; i++){
        addFirst(&list_b, atoi(argv[(argc-1)-i]));
        }
    struct Node *c;
    c =  mergeTwoLists(list_a.first, list_b.first);
    // print mergeed lists
    while (c){
        printf("%d", c ->data);
        c = c->next;
    }
    
}

void addFirst(SLList *LL, int x){
    struct Node *newFirst;
    newFirst = createNode(x);
    newFirst -> next = LL -> first;
    LL -> first = newFirst;
    LL -> size++;
}