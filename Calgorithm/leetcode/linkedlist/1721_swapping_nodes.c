#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

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

struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* curr = head;
    int list[MAX];
    int num = 0;
    while(curr){
        list[num] = curr->val;
        curr = curr->next;
        num++;
    }
    int x = list[num - k];
    list[num - k] = list[k-1];
    list[k-1] = x;
    struct ListNode h;
    struct ListNode* link = &h;
    for(int i = 0; i < num; i++){
        struct ListNode* newNode;
        newNode = createNode(list[i]);
        link->next = newNode;
        link = link->next;
    }
    link = &h;
    link = link->next;
    return link;
}

int main(){
    int head[] = {7,9,6,6,7,8,3,0,9,5};
    int k = 5;
    int size = sizeof(head) / sizeof(head[0]);
    struct ListNode h;
    struct ListNode* link = &h;
    for(int i = 0; i < size; i++){
        struct ListNode* newNode;
        newNode = createNode(head[i]);
        link->next = newNode;
        link = link->next;
    }
    link = &h;
    link = link->next;
    struct ListNode* result = swapNodes(link, k);
    // struct ListNode* result = reverseNode(link);
    
    for(int i = 0; i < size; i++){
        printf("%d ", result->val);
        result = result->next;
    }
    return 0;
}