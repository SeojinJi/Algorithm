#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void divideList(struct Node* a){
    struct Node oddh;
    struct Node evenh;
    struct Node* odd = &oddh;
    struct Node* even = &evenh;
    while(a){
        if(a -> data % 2 == 0){
            even->next = a;
            a = a->next;
            even = even->next;
        }
        else{
            odd->next = a;
            a = a->next;
            odd = odd->next;
        }
    }
    even->next = NULL;
    odd->next = NULL;

    odd = &oddh;
    odd = odd->next;

    even = &evenh;
    even = even->next;

    while(odd){
        printf("%d ", odd->data);
        odd = odd->next;
    }
    printf("\n");
    while(even){
        printf("%d ", even->data);
        even = even->next;
    }
}

struct Node* createNode(int x){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
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

int main(int argc, char* argv[]){
    int length = argc - 1;
    SLList list_a = {NULL, 0};
    for(int i = length; i > 0; i++){
        addFirst(&list_a, atoi(argv[i]));
    }

    divideList(list_a.first);

    return 0;
}

void addFirst(SLList *LL, int x){
    struct Node *newFirst;
    newFirst = createNode(x);
    newFirst->next = LL->first;
    LL->first = newFirst;
    LL->size++;
}