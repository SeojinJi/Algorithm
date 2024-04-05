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

int pairSum(struct ListNode* head){
    int range[100000];
    int index = 0;
    while(head){
        range[index] = head->val;
        head = head->next;
        index++;
    }
    int largest = 0;
    for(int i = 0; i < index /2 ; i++){
        int number = range[i] + range[index - 1 - i];
        if(largest < number){
            largest = number;
        }
    }
    return largest;
}

int main(){
    int head[] = {4, 2, 100000, 10000};
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
    int result = pairSum(list);
    printf("%d", result);
    return 0;
}