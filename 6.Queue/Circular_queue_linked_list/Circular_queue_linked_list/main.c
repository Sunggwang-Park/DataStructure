//
//  main.c
//  Circular_queue_linked_list
//
//  Created by APPLE on 26/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode{
    element item;
    struct QueueNode *link;
}QueueNode;
typedef struct{
    QueueNode *front, *rear;
}QueueType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//초기화 함수
void init(QueueType *q)
{
    q->front = q->rear = NULL;

}

//공백 함수
int is_empty(QueueType *q)
{
    return q->front == NULL;
    
}

//삽입 함수
void enqueue(QueueType *q, element item)
{
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    if (temp == NULL) {
        error("메모리 할당 오류 - 삽입할 노드의 메모리가 할당 되지 않습니다");
    }
    temp->item = item;
    temp->link = NULL;
    if(is_empty(q)){       //공백 큐일때
        q->front = temp;
        q->rear = temp;
    }
    else{                   //큐가 공백이 아니면
        q->rear->link = temp;
        q->rear = temp;
    }
}

element dequeue(QueueType *q)
{
    if(is_empty(q))
        error("삭제 함수 오류 - 큐가 공백상태입니다");
    
    QueueNode *temp = q->front;
    q->front = q->front->link;
    
    element item = temp->item;
    if (q->front==NULL) {       //공백상태
        q->rear = NULL;
    }
    free(temp);                 //노드 메모리 해제
    return item;                //데이터 반환
    
}

element peek(QueueType *q)
{
    if(is_empty(q))
        error("미리보기 오류 - 큐가 공백상태입니다");
    return q->front->item;
}

int main(int argc, const char * argv[]) {
    
    QueueType q;
    
    init(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("peek() = %d\n", peek(&q));
    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
    
    printf("peek() = %d\n", peek(&q));
    
    return 0;
}
