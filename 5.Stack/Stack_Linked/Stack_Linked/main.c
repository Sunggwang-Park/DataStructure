//
//  main.c
//  Stack_Linked
//
//  Created by APPLE on 24/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct StackNode{
    element data;
    struct StackNode *link;
}StackNode;

typedef struct LinkedStackType{
    StackNode *top;
}LinkedStackType;

//초기화 함수
void init(LinkedStackType *s)
{
    s->top = NULL;
}

//공백 상태 검출 함수
int is_empty(LinkedStackType *s)
{
    return s->top == NULL;
}

void push(LinkedStackType *s, element data)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    if (p == NULL) {
        fprintf(stderr, "노드 메모리 할당 오류");
        return;
    }
 
    p->data = data;
    p->link = s->top;
    s->top = p;
    
}

element pop(LinkedStackType *s)
{
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러 - 스택이 비어있어서 삭제할 수 없음");
        exit(1);
    }
    
    StackNode *temp = s->top;
    element item = temp->data;
    s->top = s->top->link;
    free(temp);
    return item;
    
}

element peek(LinkedStackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러 - 스택이 비어있어서 미리볼 수 없음");
        exit(1);
    }
    
    return s->top->data;
}
int main(int argc, const char * argv[]) {
    LinkedStackType s;
    
    init(&s);
    push(&s, 1);
    push(&s, 2);
    printf("%d\n", peek(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", is_empty(&s));
    return 0;
}
