#include <stdio.h>
#include <stdlib.h>

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

struct ListNode* oddEvenList(struct ListNode* head) {
    if(head == NULL){
        return NULL;
    }
    struct ListNode o;
    struct ListNode* odd = &o;
    struct ListNode e;
    struct ListNode* even = &e;
    int num = 1;
    while(head){
        if(num % 2 == 1){
            struct ListNode* newNode;
            newNode = createNode(head->val);
            odd->next = newNode;
            odd = odd->next;
            head = head->next;
            num++;
        }
        else{
            struct ListNode* newNode;
            newNode = createNode(head->val);
            even->next = newNode;
            even = even->next;
            head = head->next;
            num++;
        }
    }
    if(num == 2){
        return odd;
    }
    even = &e;
    even = even->next;
    odd->next = even;
    odd = &o;
    odd = odd->next;
    return odd;
}


int main(){
    int head[] = {1};
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
    struct ListNode* result = oddEvenList(link);
    while(result){
        printf("%d ", result->val);
        result = result->next;
    }
    return 0;
}