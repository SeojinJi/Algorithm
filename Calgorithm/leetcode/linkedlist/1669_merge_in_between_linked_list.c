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

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    int number = 0;
    struct ListNode* first = list1;
    struct ListNode* second = list1;
    while(number < a - 1){
        first = first->next;
        second = second->next;
        number++;
    }
    while(number < b + 1){
        second = second->next;
        number++;
    }
    first->next = list2;
    while(list2->next){
        list2 = list2->next;
    }
    list2->next = second;
    return list1;
}

int main(){
    int head1[] = {0,1,2,3,4,5};
    int head2[] = {1000000,1000001,1000002};
    int a = 3;
    int b = 4;
    int size_a = sizeof(head1) / sizeof(head1[0]);
    int size_b = sizeof(head2) / sizeof(head2[0]);

    struct ListNode h1;
    struct ListNode* list_a = &h1;
    for(int i = 0; i < size_a; i++){
        struct ListNode* newNode;
        newNode = createNode(head1[i]);
        list_a->next = newNode;
        list_a = list_a->next;
    }
    struct ListNode h2;
    struct ListNode* list_b = &h2;
    for(int i = 0; i < size_b; i++){
        struct ListNode* newNode;
        newNode = createNode(head2[i]);
        list_b->next = newNode;
        list_b = list_b->next;
    }


    list_a = &h1;
    list_a = list_a->next;
    list_b = &h2;
    list_b = list_b->next;

    struct ListNode* result = mergeInBetween(list_a, a, b, list_b);
    while(result){
        printf("%d ", result->val);
        result = result->next;
    }
    return 0;
}