//
//  main.c
//  Stack_maze
//
//  Created by APPLE on 26/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct{
    short r;
    short c;
} element;

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
        exit(1);
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

element here = {1,0}, entry = {1,0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'}
    
};

void push_loc(StackType *s, int r, int c)
{
    if (r < 0 || c < 0 ) return;
    if (maze[r][c] != '1' && maze[r][c] != '.') {//벽이 아니고 방문되지 않았으면
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

void main() {
    
    int r, c;
    StackType s;
    
    init(&s);
    here = entry;
    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        push_loc(&s, r-1, c);
        push_loc(&s, r+1, c);
        push_loc(&s, r, c-1);
        push_loc(&s, r, c+1);
        if(is_empty(&s)){
            printf("실패\n");
            return;
        }
        else
            here = pop(&s);
    }
    printf("성공\n");
    

}
