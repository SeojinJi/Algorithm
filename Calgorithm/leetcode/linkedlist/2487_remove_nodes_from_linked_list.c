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

// struct ListNode* removeNodes(struct ListNode* head) { // time limit exceed
//     struct ListNode* curr = head;
//     int arr[MAX];
//     int index = 0;
//     while(curr){
//         arr[index] = curr->val;
//         curr = curr->next;
//         index++;
//     }
//     int result[MAX];
//     int rindex = 0;
//     for(int i = 0; i < index; i++){
//         int flag = 0;
//         for(int j = i+1; j < index; j++){
//             if(arr[i] < arr[j]){
//                 flag = 1;
//                 break;
//             }
//         }
//         if(flag == 0){
//             result[rindex] = arr[i];
//             rindex++;
//         }
//     }
//     struct ListNode h;
//     struct ListNode* list = &h;
//     for(int i = 0; i < rindex; i++){
//         struct ListNode* newNode;
//         newNode = createNode(result[i]);
//         list->next = newNode;
//         list = list->next;
//     }
//     list = &h;
//     list = list->next;
//     return list;
// }

struct ListNode* removeNodes(struct ListNode* head){
    if(head == NULL){
        return NULL;
    }
    head->next = removeNodes(head->next);
    if(head->next != NULL && head->val < head->next->val){
        return head->next;
    }
    return head;
}

int main(){
    int head[] = {5,2,13,3,8};
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
    struct ListNode* result = removeNodes(list);
    while(result){
        printf("%d ", result->val);
        result = result->next;
    }
    return 0;
}