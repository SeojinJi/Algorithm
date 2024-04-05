#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int x);

void divideList(struct Node* a){
    struct Node *odd_head = createNode(0);
    struct Node *even_head = createNode(0);

    struct Node *odd_curr = odd_head;
    struct Node *even_curr = even_head;

    while(a){
        if(a->data % 2 == 0){
            even_curr->next = a;
            even_curr = even_curr->next;
        }
        else{
            odd_curr->next = a;
            odd_curr = odd_curr->next;
        }
        a = a->next;
    }
    even_curr->next = NULL;
    odd_curr->next = NULL;

    odd_curr = odd_head->next;
    even_curr = even_head->next;

    printf("odd : ");
    while(odd_curr){
        printf("%d ", odd_curr->data);
        odd_curr = odd_curr->next;
    }
    printf("\n");
    printf("even : ");
    while(even_curr){
        printf("%d ", even_curr->data);
        even_curr = even_curr->next;
    }
}


struct Node* mergeTwoLists(struct Node* a, struct Node* b){
    struct Node h;
    struct Node* result = &h;
    if(a==NULL && b==NULL){
        return NULL;
    }
    while(a && b){
        if(a->data < b->data){
            result->next = a;
            a = a->next;
            result = result->next;
        }
        else{
            result->next = b;
            b = b->next;
            result = result->next;
        }
    }
    if(a){
        result->next = a;
    }
    if(b){
        result->next = b;
    }
    result = &h;

    return result->next;

}

struct Node* createNode(int x){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
typedef struct listType SLList;
struct listType{
    struct Node *first;
    int size;
};

void addFirst(SLList *LL, int x);

// int main(int argc, char* argv[]){
//     SLList list_a = {NULL, 0};
//     SLList list_b = {NULL, 0};
//     for(int i = 0; i < (argc-1)/2; i++){
//         addFirst(&list_a, atoi(argv[(argc-1)/2 - i]));
//     }
//     for(int i = 0; i < argc / 2; i++){
//         addFirst(&list_b, atoi(argv[argc - 1 - i]));
//     }
//     struct Node *c;
//     c = mergeTwoLists(list_a.first, list_b.first);
//     while(c){
//         print("%d ", c->data);
//         c = c->next;
//     }
//     return 0;
// }

// int main(int argc, char* argv[]){
//     int length = argc - 1;
//     SLList list = {NULL, 0};
//     for(int i = 0; i < argc-1; i++){
//         addFirst(&list, atoi(argv[argc - 1 - i]));
//     }
//     struct Node* head = list.first;
//     struct Node* curr = head;
//     struct Node* prevNode = NULL;
//     struct Node* nextNode = NULL;
//     while(curr){
//         nextNode = curr->next;
//         curr->next = prevNode;
//         prevNode = curr;
//         curr = nextNode;
//     }
//     head = prevNode;
//     curr = head;
//     while(curr){
//         printf("%d", curr->data);
//         curr = curr->next;
//     }
//     return 0;
// }


int main(int argc, char* argv[]){
    SLList LL = {NULL, 0};
    for(int i = 0; i < argc-1; i++){
        addFirst(&LL, atoi(argv[argc - 1 -i]));
    }
    divideList(LL.first);
    return 0;
}

void addFirst(SLList *LL, int x){
    struct Node* newFirst;
    newFirst = createNode(x);
    newFirst->next = LL->first;
    LL->first = newFirst;
    LL->size++;
}