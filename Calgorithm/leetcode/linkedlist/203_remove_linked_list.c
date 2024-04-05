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

struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL){
        return head;
    }
    struct ListNode o;
    struct ListNode* output = &o;
    int result = 0;
    while(head){
        if(head->val == val){
            head = head->next;
        }
        else{
            struct ListNode* newNode;
            newNode = createNode(head->val);
            output->next = newNode;
            output = output->next;
            head = head->next;
            result += 1;
        }
    }
    if(result == 0){
        return NULL;
    }
    output = &o;
    return output->next;
}

int main(){
    int head[] = {7, 7, 7, 7};
    int size = sizeof(head) / sizeof(head[0]);
    int val = 7;
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
    struct ListNode* result = removeElements(list, val);
    while(result){
        printf("%d ", result->val);
        result = result->next;
    }
    return 0;
}