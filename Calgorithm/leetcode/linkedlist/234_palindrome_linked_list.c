#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int x){
    struct ListNode* newNode;
    newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = x;
    newNode->next = NULL;
    return newNode;
}

bool isPalindrome(struct ListNode* head) {
    int palin[100000];
    int index = 0;
    while(head){
        palin[index] = head->val;
        head = head->next;
        index++;
    }
    for(int i = 0; i < index; i++){
        if(palin[i] != palin[index-1-i]){
            return false;
        }
    }
    return true;
}

int main(){
    int head[] = {1, 2, 2, 1};
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
    bool result = isPalindrome(link);
    printf("%d", result);
    return 0;
}