#include <stdio.h>
#include <string.h>
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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* curr = head;
    int num = 0;
    while(curr){
        num++;
        curr = curr->next;
    }
    if(num == 1){
        return NULL;
    }
    int index = 0;
    curr = head;
    while(curr){
        printf("%d, %d\n", index, curr->val);
        if(index == num - n - 1){
            curr->next = curr->next->next;
            curr = curr->next;
            index += 2;
        }
        else{
            curr = curr->next;
            index++;
        }
    }

    if(num == n){
        curr = head->next;
    }
    else{
        curr = head;
    }
    
    return curr;
}

int main(){
    int head[] = {1,2,3,4,5};
    int size = sizeof(head) / sizeof(head[0]);
    int n = 2;
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
    struct ListNode* result = removeNthFromEnd(list, n);
    while(result){
        printf("%d ", result->val);
        result = result->next;
    }
    return 0;
}