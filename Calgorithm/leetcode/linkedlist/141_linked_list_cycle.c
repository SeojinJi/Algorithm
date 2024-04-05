#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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


bool hasCycle(struct ListNode *head) {
    struct ListNode *curr = head;
    int i = 1;
    while(curr){
        curr = curr->next;
        i++;
        if(i > 10001){
            return true;
        }
    }
    return false;
}

int main(){
    int head[] = {3, 2, 0, -4};
    int pos = 1;

    int size = sizeof(head) / sizeof(head[0]);
    struct ListNode h;
    struct ListNode* link = &h;
    for(int i = 0; i < size; i++){
        struct ListNode* newNode;
        newNode = createNode(head[i]);
        link->next = newNode;
        link = link->next;
    }

    struct ListNode* curr = &h;
    curr = curr->next;
    int i = 0;
    while(i < pos){
        curr = curr->next;
        i++;
    }
    link->next = curr;
    link = &h;
    link = link->next;
    int result = hasCycle(link);
    printf("%d", result);
    return 0;
}