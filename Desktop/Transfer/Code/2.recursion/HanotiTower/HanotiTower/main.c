//
//  main.c
//  HanotiTower
//
//  Created by APPLE on 16/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>

//재귀로 구현된 하노이
void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n == 1){
        printf("원판 1을 %c에서 %c로 옮긴다\n",from,to);
    }
    else{
        hanoi_tower(n-1, from, to, tmp);
        printf("원판 %d를 %c에서 %c로 옮긴다\n",n,from,to);
        hanoi_tower(n-1, tmp, from, to);
    }
}


//비재귀 하노이 타워
// 비재귀에 사용하기 위한 스택
#define MAX 100
int stack[MAX];        // 스택의 긴  통
int top;            // 스택의 상단




void init_stack(void){
    top = -1;
}

int push(int t){
    
    if (top >= MAX - 1){
        printf("\n    Stack overflow.");
        return -1;
    }
    
    stack[++top] = t;
    return t;
}

int pop(void){
    if (top < 0){
        printf("\n   Stack underflow.");
        return -1;
    }
    return stack[top--];
}

int is_stack_empty(){
    return (top > -1) ? 0 : 1;
}

// 하노이의 탑 비재귀로 변환
void nr_hanoi(int n, int from, int by, int to){
    
    init_stack();
    while (1){
        while (n > 1){
            push(to);    // 인자리스트 푸쉬
            push(by);
            push(from);
            push(n);
            n--;        // 인자리스트 변경 1
            push(to);    // to 와 by를 교환하기 위해 임시로 저장
            to = by;
            by = pop();
        }
        
        printf("\n disk %d : Move from %c to %c", n, from, to);        // 재귀의 마지막 종료 처리
        
        if (!is_stack_empty()){
            n = pop();
            from = pop();
            by = pop();
            to = pop();
            
            printf("\n disk %d : Move from %c to %c", n, from, to);        // 실제 이동 작업
            
            n--;        // 인자리스트 변경 2
            push(from);
            from = by;
            by = pop();
        }
        else{
            break;
        }
    }
}




int main(int argc, const char * argv[]) {
    nr_hanoi(4, 'A', 'B', 'C');
 //   hanoi_tower(4, 'A', 'B', 'C');
    
    
    return 0;
}
