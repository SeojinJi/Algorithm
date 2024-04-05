#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1001

typedef struct{
    int items[MAX_SIZE]; // 스택에 저장되는 요소들을 저장하는 배열
    int top; // 스택의 맨 위 요소의 인덱스를 나타냄
} Stack;

void initStack(Stack *stack){ // 스택 초기화
    stack->top = -1;
}

int isEmpty(Stack *stack){ // 스택이 비어있는지 확인
    return stack->top == -1;
}

int isFull(Stack *stack){ // 스택이 꽉차있는지 확인
    return stack->top == MAX_SIZE -1;
}

void push(Stack *stack, int value){ // 스택에 요소 추가
    if(isFull(stack)){
        return;
    }
    stack->items[++stack->top] = value;
}

// int pop(Stack *stack){ // 스택 맨 위 요소 제거
//     if(isEmpty(stack)){
//         exit(1);
//     }
//     return stack->items[stack->top--];
// }

void pop(Stack *stack){ // 이건 pop만 하는 것. item 안 나옴
    if(isEmpty(stack)){
        exit(1);
    }
    stack->top--;
}

int peak(Stack *stack){ // 스택 맨 위 요소 반환
    if(isEmpty(stack)){
        exit(1);
    }
    return stack->items[stack->top];
}

void printStack(Stack *stack){
    for(int i = stack->top; i >= 0; i--){
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}


int minAddToMakeValid(char* s) {
    int length = strlen(s);
    int result = 0;
    Stack stack;
    initStack(&stack);
    for(int i = 0; i < length; i++){
        if(s[i] == '('){
            push(&stack, 1);
        }
        else if(s[i] == ')' && isEmpty(&stack)){
            result++;
        }
        else if(s[i] == ')' && isEmpty(&stack) == 0){
            pop(&stack);
        }
    }
    result += (stack.top+1);
    return result;
}

int main(){
    char* s = "(()())((";
    int result = minAddToMakeValid(s);
    printf("%d",result);
    return 0;
}