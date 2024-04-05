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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL && list2 == NULL){
        return NULL;
    }
    else if(list1 == NULL){
        return list2;
    }
    else if(list2 == NULL){
        return list1;
    }
    struct ListNode h;
    struct ListNode* result = &h;
    while(list1 && list2){
        if(list1->val >= list2->val){
            result->next = list2;
            result = result->next;
            list2 = list2->next;
        }
        else{
            result->next = list1;
            result = result->next;
            list1 = list1->next;
        }
    }
    if(list1){
        result->next = list1;
    }
    if(list2){
        result->next = list2;
    }
    result = &h;
    result = result->next;
    return result;
}

int main(){
    int head1[] = {1,2,4};
    int head2[] = {1,3,4};
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

    struct ListNode* result = mergeTwoLists(list_a, list_b);
    while(result){
        printf("%d ", result->val);
        result = result->next;
    }
    return 0;
}