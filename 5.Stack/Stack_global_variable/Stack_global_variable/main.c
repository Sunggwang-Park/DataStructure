//
//  main.c
//  Stack_global_variable
//
//  Created by APPLE on 24/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//


//전역 변수로 구현한 스택 - 비효율적
// 하나 이상의 스택을 사용해야 할때는 곤란하게 됨
// 전역 변수를 사용하는 것은 프로그램을 복잡하게 만들어서 오류가 발생할 가능성이 높아짐
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

//공백 상태 검출 함수
int is_empty()
{
    return (top == -1);
}

//포화 상태 검출 함수
int is_full()
{
    return (top == MAX_STACK_SIZE-1);
}

void push(element item)
{
    if (is_full()) {
        fprintf(stderr, "스택 포화 에러 - 스택이 꽉 차서 요소를 집어넣을수 없음\n");
        return;
    }
    else
        stack[++top] = item;
}

element pop()
{
    if (is_empty()) {
        fprintf(stderr, "스택 공백 에러 - 스택이 이미 비어있어서 삭제할 수 없음\n");
        exit(1);
    }
    else return stack[top--];
}

element peek()
{
    if (is_empty()) {
        fprintf(stderr, "스택 공백 에러 - 스택이 비어있어서 peek할 수 없음\n");
        exit(1);
    }
    else return stack[top];
}

int main(int argc, const char * argv[]) {
    
    push(1);
    push(2);
    push(3);
    printf("%d\n",peek());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    
    printf("%d\n",peek());
    
    
  
    return 0;
}
