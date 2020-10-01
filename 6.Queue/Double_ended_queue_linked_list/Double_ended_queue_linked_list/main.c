//
//  main.c
//  Double_ended_queue_linked_list
//
//  Created by APPLE on 26/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE

typedef int element;

typedef struct DlistNode{
    element data;
    struct DlistNode *llink, *rlink;
}DlistNode;

typedef struct DequeType{
    DlistNode *head, *tail;
   
}DequeType;

void error(char *message)
{
    fprintf(stderr, "%s\n",message);
    exit(1);
}

void init(DequeType *dq)
{
    dq->head = dq->tail = NULL;
}

DlistNode *creat_node(DlistNode *llink, element item, DlistNode *rlink)
{
    DlistNode *temp = (DlistNode *)malloc(sizeof(DlistNode));
    if(temp == NULL)
        error("노드 메모리 할당 오류");
    
    temp->data = item;
    temp->llink = llink;
    temp->rlink = rlink;
    
    return temp;
}

int is_empty(DequeType *dq)
{
    return dq->head == NULL;
}

void add_rear(DequeType *dq, element item)
{
    DlistNode *node = creat_node(dq->tail, item, NULL);
    if(is_empty(dq))
        dq->head = node;
    else
        dq->tail->rlink = node;
    dq->tail = node;
    
}

void add_front(DequeType *dq, element item)
{
    DlistNode *node = creat_node(NULL, item, dq->head);
    if (is_empty(dq))
        dq->tail = node;
    else
        dq->head->llink = node;
    dq->head = node;

}

element delete_front(DequeType *dq)
{
    DlistNode *removed_node;
    element item;
    if(is_empty(dq))
        error("전단삭제 오류 - 공백 덱");
    else{
        removed_node = dq->head;
        item = removed_node->data;
        dq->head = dq->head->rlink;
        free(removed_node);
        if(dq->head == NULL)
            dq->tail = NULL;
        else
            dq->head->llink = NULL;
    }
    
    return item;
    
}

element delete_rear(DequeType *dq)
{
    DlistNode *removed_node;
    element item;
    if(is_empty(dq)) error("후단삭제 오류 - 공백 덱");
    else{
        removed_node = dq->tail;
        item = removed_node->data;
        dq->tail = dq->tail->llink;
        free(removed_node);
        
        if(dq->tail == NULL)
            dq->head = NULL;
        else
            dq->tail->rlink = NULL;

    }
    return item;
}

void display(DequeType *dq)
{
    if(is_empty(dq)) error("출력 오류 - 공백덱");
    
    for (DlistNode *node = dq->head; node != NULL; node = node->rlink) {
        printf("%d ",node->data);
    }
    
    printf("\n");
}

int main(int argc, const char * argv[]) {
    
    DequeType deque  , deque2;
    
    init(&deque);
    
    add_front(&deque, 10);
    add_front(&deque, 20);
    add_rear(&deque, 30);
    display(&deque);
    
    delete_front(&deque);
    delete_rear(&deque);
    display(&deque);
    
    init(&deque2);
    add_front(&deque2,  50);
    display(&deque2);
    
    return 0;
}
