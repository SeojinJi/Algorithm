#include <stdio.h>
#include <string.h>
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

struct ListNode* reverseNode(struct ListNode* h1){
    struct ListNode* prev = NULL;
    struct ListNode* curr = h1;
    struct ListNode* next = NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr = prev;
    return curr;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* h1 = reverseNode(l1);
    struct ListNode* h2 = reverseNode(l2);
    unsigned long long num1 = 0;
    while(h1){
        num1 = (num1 * 10) + (h1->val);
        h1 = h1->next;
    }
    unsigned long long num2 = 0;
    while(h2){
        num2 = (num2 * 10) + (h2->val);
        h2 = h2->next;
    }
    unsigned long long result = num1 + num2;
    printf("%d", result);
    struct ListNode p;
    struct ListNode* resultlink = &p;
    while(result > 0){
        int number = result % 10;
        struct ListNode* newNode;
        newNode = createNode(number);
        resultlink->next = newNode;
        resultlink = resultlink->next;
        result = result / 10;
    }
    resultlink = &p;
    resultlink = resultlink->next;
    return resultlink;
}

int main(){
    int head1[] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    int head2[] = {5,6,4};
    int size1 = sizeof(head1) / sizeof(head1[0]);
    int size2 = sizeof(head2) / sizeof(head2[0]);
    struct ListNode h1;
    struct ListNode* link1 = &h1;
    for(int i = 0; i < size1; i++){
        struct ListNode* newNode;
        newNode = createNode(head1[i]);
        link1->next = newNode;
        link1 = link1->next;
    }
    link1 = &h1;
    link1 = link1->next;

    struct ListNode h2;
    struct ListNode* link2 = &h2;
    for(int i = 0; i < size2; i++){
        struct ListNode* newNode;
        newNode = createNode(head2[i]);
        link2->next = newNode;
        link2 = link2->next;
    }
    link2 = &h2;
    link2 = link2->next;

    struct ListNode* result = addTwoNumbers(link1, link2);
    // struct ListNode* result = reverseNode(link1);

    while(result){
        printf("%d", result->val);
        result = result->next;
    }
    return 0;

}