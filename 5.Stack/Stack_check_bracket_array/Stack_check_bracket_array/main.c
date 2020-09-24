//
//  main.c
//  Stack_check_bracket_array
//
//  Created by APPLE on 24/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0;
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

int check_matching(char *in)
{
    StackType s;
    char ch, open_ch;
    int n = strlen(in);
    init(&s);
    
    for (int i=0; i < n; i++) {
        ch = in[i];
        switch (ch) {
            case '(':
            case '[':
            case '{':
                push(&s, ch);
                break;
                
            case ')':
            case ']':
            case '}':
                if (is_empty(&s)) {
                    return FALSE;
                }
                else{
                    open_ch = pop(&s);
                    if((open_ch == '(' && ch != ')') ||
                       (open_ch == '[' && ch != ']') ||
                       (open_ch == '{' && ch != '}')) {
                        return FALSE;
                    }
                }
                break;
     
        }
    }
    if(!is_empty(&s)) return FALSE;
    return TRUE;
}

int main(int argc, const char * argv[]) {
    
    if (check_matching("{A[(i+1)] + 1}") == TRUE) {
        printf("괄호검사 합격\n");
    }
    else printf("괄호 부적격\n");
    return 0;
}
