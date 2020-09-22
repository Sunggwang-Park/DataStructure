//
//  main.c
//  Infix_to_postfix
//
//  Created by APPLE on 25/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>


#define MAX_STACK_SIZE 100
typedef char element;
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

//연산자의 우선순위를 반환한다
int prec(char op)
{
    switch(op){
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;

    }
    return -1;
}

//중위 표기 수식 -> 후위 표기 수식
void infix_to_postfix(char exp[])
{
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;
    
    init(&s);
    for (i=0; i<len; i++) {
        ch = exp[i];
        switch(ch){
            case '+': case '-': case '*': case '/':
                //스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
                while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
                    printf("%c", pop(&s));
                }
                push(&s,ch);
                break;
            case '(':
                push(&s, ch);
                break;
            case ')':
                top_op = pop(&s);
                //왼쪽 괄호를 만날 때까지 출력
                while (top_op != '(') {
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                break;
            default:                //피연산자
                printf("%c",ch);
                break;
        }
    }
    while (!is_empty(&s))          //스택에 저장된 연산자들 출력
        printf("%c", pop(&s));
    
    
}

int main(int argc, const char * argv[]) {
    infix_to_postfix("(2+3)*4+9\n");
    return 0;
}
