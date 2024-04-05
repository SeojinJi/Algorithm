#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int getDecimalValue(struct ListNode* head){
    int decimal[30];
    struct ListNode* curr = head;
    int index = 0;
    while(curr){
        decimal[index] = curr->val;
        curr = curr->next;
        index++;
    }
    int result = 0;
    for(int i = index-1; i > -1; i--){
        int number = decimal[i] *pow(2, index - i - 1);
        result += number;
    }
    return result;
}

int main(){
    int head[] = {1, 0, 1, 1};
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
    int result = getDecimalValue(list);
    printf("%d", result);
    return 0;
}