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

struct ListNode* middleNode(struct ListNode* head) {
    int number = 0;
    struct ListNode* hello = head;
    while(hello){
        hello = hello->next;
        number++;
    }
    number = (number / 2) + 1;
    int n = 1;
    hello = head;
    while(hello){
        if(n == number){
            return hello;
        }
        hello = hello->next;
        n++;
    }
}

int main(){
    int head[] = {1,2,3,4,5,6};

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
    struct ListNode* result = middleNode(link);
    while(result){
        printf("%d ", result->val);
        result = result->next;
    }
    return 0;
}