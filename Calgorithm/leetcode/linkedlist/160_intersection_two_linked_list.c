#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int x){
    struct ListNode* newNode;
    newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* output = headB;
    while(headA){
        while(output){
            if(output == headA){
                return output;
            }
            output = output->next;
        }
        output = headB;
        headA = headA->next;
    }
    return NULL;
}

int main(){
    int intersectVal = 8;
    int listA[] = {4, 1, 8, 4, 5};
    int listB[] = {5, 6, 1, 8, 4, 5};
    int skipA = 2;
    int skipB = 3;

    int sizeA = sizeof(listA) / sizeof(listA[0]);
    int sizeB = sizeof(listB) / sizeof(listB[0]);

    struct ListNode hA;
    struct ListNode* linkA = &hA;
    for(int i = 0; i <sizeA; i++){
        struct ListNode* newNode;
        newNode = createNode(listA[i]);
        linkA->next = newNode;
        linkA = linkA->next;
    }
    linkA = &hA;
    linkA = linkA->next;
    int number = 0;
    while(number < skipA){
        linkA = linkA->next;
        number++;
    }
    int numberB = 0;
    struct ListNode hB;
    struct ListNode* linkB = &hB;
    while(numberB < skipB){
        struct ListNode* newNode;
        newNode = createNode(listB[numberB]);
        linkB->next = newNode;
        linkB = linkB->next;
        numberB++;
    }
    linkB->next = linkA;
    linkA = &hA;
    linkA = linkA->next;
    linkB = &hB;
    linkB = linkB->next;
    // while(linkA){
    //     printf("%d ", linkA->val);
    //     linkA = linkA->next;
    // }
    // printf("\n");
    // while(linkB){
    //     printf("%d ", linkB->val);
    //     linkB = linkB->next;
    // }
    struct ListNode* result = getIntersectionNode(linkA, linkB);
    while(result){
        printf("%d ", result->val);
        result = result->next;
    }
    return 0;
}