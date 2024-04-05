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

struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* curr = head->next;
    struct ListNode h;
    struct ListNode* model = &h;
    int number = 0;
    while(curr){
        if(curr->val == 0){
            struct ListNode* newNode = createNode(number);
            model->next = newNode;
            model = model->next;
            number = 0;
            curr = curr->next;
        }
        else{
            number += curr->val;
            curr = curr->next;
        }
    }
    model = &h;
    return model->next;
}

int main(){
    int head[] = {0,1,0,3,0,2,2,0};
    int size = sizeof(head) / sizeof(head[0]);
    struct ListNode h;
    struct ListNode* list = &h;
    for(int i = 0; i < size; i++){
        struct ListNode* newNode;
        newNode = createNode(head[i]);
        list->next = newNode;
        list = list->next;
    }
    list = &h;
    list = list->next;
    struct ListNode* result = mergeNodes(list);
    while(result){
        printf("%d ", result->val);
        result = result->next;
    }
    return 0;
}