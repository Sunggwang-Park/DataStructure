//
//  main.c
//  Binary_Heap
//
//  Created by APPLE on 03/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>

#define MAX_ELEMENT 200

typedef struct{
    int key;
}element;

typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;


void init(HeapType *h)
{
    h->heap_size = 0;
    
}
//현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다
void insert_max_heap(HeapType *h, element item)
{
    int i = ++(h->heap_size);
    
    //트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i != 1) && item.key > h->heap[i/2].key) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;  //새로운 노드를 삽입

}

//삭제 함수
element delete_max_heap(HeapType *h)
{
    int parent = 0 , child = 0;
    element item, temp;
    
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        //현재 노드의 자식 노드 중 더 큰 자식을 찾는다
        if (child < h->heap_size && h->heap[child].key < h->heap[child+1].key) {
            child++;
        }
        if(temp.key >= h->heap[child].key) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
        
    }
    h->heap[parent] = temp;
    return item;
}
int power( int x, int y)
{
    if(y == 0) return 1;
    
    else if(y % 2 == 0)
        return power(x*x, y/2);
    
    else
        return x * power(x*x, (y-1)/2);
    
}

void print_heap(HeapType *h)
{
    int count = 1;
    
    
    for (int i =1; i <= h->heap_size; i++) {
        if (i  == power(2, count)){
            printf("\n");
            count++;
        }
        
        printf("%d  ", h->heap[i].key);
        
        
    }
}


int main(int argc, const char * argv[]) {
    
    element e1 = {10}, e2 = {5}, e3 = {30} , e4 = {20};
    element  e5, e6;
    HeapType heap;  //히프 생성
    
    init(&heap);    //초기화
    
    //삽입
    insert_max_heap(&heap, e1);
    insert_max_heap(&heap, e2);
    insert_max_heap(&heap, e3);
    insert_max_heap(&heap, e4);
    
    print_heap(&heap);
    
    return 0;
}
