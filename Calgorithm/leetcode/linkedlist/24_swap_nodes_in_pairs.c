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

struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL){
        return NULL;
    }
    struct ListNode* curr = head;
    int arr[100];
    int index = 0;
    while(curr){
        arr[index] = curr->val;
        curr = curr->next;
        index++;
    }
    int number = 0;
    while(number < index && number + 1 < index){
        int first = number;
        int second = number+1;
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
        number += 2;
    }
    struct ListNode h;
    struct ListNode* list = &h;
    for(int i = 0; i < index; i++){
        struct ListNode* newNode;
        newNode = createNode(arr[i]);
        list->next = newNode;
        list = list->next;
    }
    list = &h;
    list = list->next;
    return list;
}

int main(){
    int head[] = {1,2,3,4,5};
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
    struct ListNode* result = swapPairs(list);
    while(result){
        printf("%d ", result->val);
        result = result->next;
    }
    return 0;
}