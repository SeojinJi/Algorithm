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


struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL){
        return head;
    }
    struct ListNode* currNode = head;
    struct ListNode* newNode = currNode->next;
    currNode->next = NULL;
    struct ListNode* parentNode = currNode;
    currNode = newNode;    
    while(currNode){
        newNode = currNode->next;
        currNode->next = parentNode;
        parentNode = currNode;
        currNode = newNode;
    }
    currNode = parentNode;
    return currNode;
}


int main(){
    int head[] = {1, 2, 3, 4, 5};
    int size = sizeof(head) / sizeof(head[0]);
    struct ListNode h;
    struct ListNode* link = &h;
    for(int i = 0; i <size; i++){
        struct ListNode* newNode;
        newNode = createNode(head[i]);
        link->next = newNode;
        link = link->next;
    }
    link = &h;
    struct ListNode* result = reverseList(link->next);
    while(result){
        printf("%d ", result->val);
        result = result->next;
    }
    return 0;
}
