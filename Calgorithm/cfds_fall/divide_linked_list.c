#include <stdio.h>
#include <stdlib.h>

/*
Sample 1)
$ ./divide_linked_list 1 2 3 4 5
odd 1 3 5 
even 2 4 

Sample 2)
$ ./divide_linked_list 2 4 6 8 10
odd
even 2 4 6 8 10 

Sample 3)
$ ./divide_linked_list
odd 
even
*/


/* Linked list node structure */
typedef struct nodeType LinkedNode;
struct nodeType{
    int val;
    LinkedNode *next;
};

typedef struct listType SLList;
struct listType{
    LinkedNode *first;
    int size;
};

/* Linked list node functions */
LinkedNode *createNode(int x);
void addFirst(SLList *LL, int x);


void divideList(LinkedNode *a){

    LinkedNode *odd_head = createNode(-1);
    LinkedNode *even_head = createNode(-1);

    /* 
    Currently, odd_head and even_head point to dummy nodes. 
    In the code you write, odd_head and even_head must never change, and must still point to these dummy nodes at the end of the code. 
    Therefore, create new pointers (for example, odd_curr, even_curr) to use.
    */

    /* Write your code here */
    LinkedNode *odd_curr = odd_head;
    LinkedNode *even_curr = even_head;

    while(a){
        if(a->val %2 == 0){
            even_curr->next = a;
            even_curr = even_curr->next;
        }
        else{
            odd_curr->next = a;
            odd_curr = odd_curr->next;
        }
        a = a->next;
    }
    even_curr->next = NULL; // 분할된 list 끝에 NULL을 안 넣어주면 끝에 이상한 값 붙음
    odd_curr->next = NULL; // 분할된 list 끝에 NULL을 안 넣어주면 끝에 이상한 값 붙음

    // DO NOT MODIFY BELOW!!!

    odd_head = odd_head->next;
    even_head = even_head->next;

    printf("odd ");
    while (odd_head){
        printf("%d ", odd_head->val);
        odd_head = odd_head->next;
    }
    printf("\n");
    printf("even ");
    while (even_head){
        printf("%d ", even_head->val);
        even_head = even_head->next;
    }
}


// DO NOT MODIFY BELOW!!!

/* Function to create a new node */
LinkedNode *createNode(int x){
    LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

void addFirst(SLList *LL, int x){
    LinkedNode *newFirst = createNode(x);
    newFirst->next = LL->first;
    LL->first = newFirst;
    LL->size++;
}

int main(int argc, char* argv[]){
    SLList LL = {NULL, 0};

    for(int i = argc-1; i > 0; i--){
        addFirst(&LL, atoi(argv[i])); 
    }

    divideList(LL.first);
    
    return 0;
}

