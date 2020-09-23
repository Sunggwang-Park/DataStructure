//
//  main.c
//  Stack_array
//
//  Created by APPLE on 24/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct{
    element stack[MAX_STACK_SIZE];
    int top;
}StackType;

//스택 초기화 함수
void init(StackType *s)
{
    s->top = -1;
}

//포화 상태 검출 함수
int is_full(StackType *s)
{
    return s->top == MAX_STACK_SIZE-1;
    
}

//공백 상태 검출 함수
int is_empty(StackType *s)
{
    return (s->top == -1);
}

void push(StackType *s, element data)
{
    if (is_full(s)) {
        fprintf(stderr, "포화 상태 오류 - 스택이 꽉차서 추가안됨");
        return;
    }
    else s->stack[++s->top] = data;
}

//삭제 함수
element pop(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "공백 상태 오류 - 스택이 이미 비어있어서 삭제할수 없음");
        return NULL;
    }
    else return s->stack[s->top--];
}

element peek(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "공백 상태 오류 - 스택이 이미 비어있어서 미리볼 수 없음");
        exit(1);        //책에 쓰여진 코드
    }
    else return s->stack[s->top];
}



int main(int argc, const char * argv[]) {
    StackType s;
    
    init(&s);
    push(&s, 1);
    push(&s, 2);
    
    printf("%d\n",peek(&s));
    printf("%d\n",pop(&s));
    printf("%d\n",pop(&s));
    printf("%d\n",pop(&s));
    printf("%d\n",peek(&s));
    
    
    return 0;
}
