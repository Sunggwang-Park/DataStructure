//
//  main.c
//  postfix_eval
//
//  Created by APPLE on 25/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

//후위 표기 수식 계산 프로그램

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

int eval(char exp[])
{
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;
    init(&s);
    for (i=0; i<len; i++) {
        ch = exp[i];
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/'){  //입력이 피연산자이면
            value = ch - '0';   //문자를 '0'으로 빼면 숫자로 바뀜
            push(&s, value);
        }
        else{
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) {
                case '+':
                    push(&s, op1+op2);
                    break;
                case '-':
                    push(&s, op1-op2);
                    break;
                case '*':
                    push(&s, op1*op2);
                    break;
                case '/':
                    push(&s, op1/op2);
                    break;

            }
        }
    }
    return pop(&s);
}


int main(int argc, const char * argv[]) {
    int result;
    printf("후위표기식은 82/3-32*+ \n");
    result = eval("82/3-32*+");
    printf("결과 : %d\n", result);
    return 0;
}
