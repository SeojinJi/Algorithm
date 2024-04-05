#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) { // 다 좋은데 이러면 숫자 커지면 감당안됨
    int num1 = 0;
    int num2 = 0;
    while(l1){
        num1 = (num1*10) + (l1->val);
        l1 = l1->next;
    }
    while(l2){
        num2 = (num2*10) + (l2->val);
        l2 = l2->next;
    }
    int result = num1 + num2;
    printf("%d\n", result);
    if(result == 0){
        struct ListNode* newNode;
        newNode = createNode(result);
        return newNode;
    }

    struct ListNode* list = NULL;
    while(result > 0){
        int number = result % 10;
        struct ListNode* newNode;
        newNode = createNode(number);
        newNode->next = list;
        list = newNode;
        result = result / 10;
    }
    return list;
}

int main(){
    int head1[] = {2, 4, 3};
    int head2[] = {5, 6, 4};
    int size_a = sizeof(head1) / sizeof(head1[0]);
    int size_b = sizeof(head2) / sizeof(head2[0]);

    struct ListNode h1;
    struct ListNode* list_a = &h1;
    for(int i = 0; i < size_a; i++){
        struct ListNode* newNode;
        newNode = createNode(head1[i]);
        list_a->next = newNode;
        list_a = list_a->next;
    }
    struct ListNode h2;
    struct ListNode* list_b = &h2;
    for(int i = 0; i < size_b; i++){
        struct ListNode* newNode;
        newNode = createNode(head2[i]);
        list_b->next = newNode;
        list_b = list_b->next;
    }

    list_a = &h1;
    list_a = list_a->next;
    list_b = &h2;
    list_b = list_b->next;

    struct ListNode* result = addTwoNumbers(list_a, list_b);
    while(result){
        printf("%d ", result->val);
        result = result->next;
    }
    return 0;
}