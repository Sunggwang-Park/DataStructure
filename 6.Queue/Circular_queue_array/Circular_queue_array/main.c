//
//  main.c
//  Circular_queue_array
//
//  Created by APPLE on 26/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct{
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//초기화 함수
void init(QueueType *q)
{
    q->front = q->rear = 0;
}

//공백 상태 검출 함수
int is_empty(QueueType *q)
{
    return q->front == q->rear;
}

//포화 상태 검출 함수
int is_full(QueueType *q)
{
    return q->front == (q->rear+1) % MAX_QUEUE_SIZE;
}

//삽입 함수
void enqueue(QueueType *q, element item)
{
    if(is_full(q)) {
        error(" 삽입 오류 - 큐가 꽉차서 더이상 데이터를 넣을 수 없습니다\n");
        
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

//삭제 함수
element dequeue(QueueType *q)
{
    if(is_empty(q)){
        error("삭제 오류 - 큐가 이미 공백상태입니다");
        
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

element peek(QueueType *q)
{
    if(is_empty(q))
        error("미리보기 오류 - 큐가 공백상태입니다");
    return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(int argc, const char * argv[]) {
    
    QueueType q;
    init(&q);
    printf("front = %d rear = %d\n", q.front, q.rear);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
    printf("dequeue() = %d\n", dequeue(&q));
    printf("front = %d rear = %d\n", q.front, q.rear);
    
    
    
    return 0;
}
