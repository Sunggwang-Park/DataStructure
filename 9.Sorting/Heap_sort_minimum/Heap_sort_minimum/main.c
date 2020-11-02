//
//  main.c
//  Heap_sort
//
//  Created by APPLE on 04/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//



//최소 히프 프로그램

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
void insert_min_heap(HeapType *h, element item)
{
    int i = ++(h->heap_size);
    
    //트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i != 1) && item.key < h->heap[i/2].key) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;  //새로운 노드를 삽입
    
}

//삭제 함수
element delete_min_heap(HeapType *h)
{
    int parent = 0 , child = 0;
    element item, temp;
    
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        //현재 노드의 자식 노드 중 더 작은 자식을 찾는다
        if (child < h->heap_size && h->heap[child].key > h->heap[child+1].key) {
            child++;
        }
        if(temp.key <= h->heap[child].key) break;
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

void heap_sort(element a[], int n)
{
    int i;
    HeapType h;
    
    init(&h);
    for (i = 0; i<n; i++) {
        insert_min_heap(&h, a[i]);
    }
    for (i=(n-1); i >= 0; i--) {
        a[i] = delete_min_heap(&h);
    }
}

void print_array(element a[], int n)
{
    for (int i=0; i < n; i++) {
        printf("%d ", a[i].key);
    }
    printf("\n");
}


int main(int argc, const char * argv[]) {
    
    element a[] = {5 ,23 ,14 ,74 ,34 ,52 ,21 ,80 ,49};
    int n = sizeof(a)/sizeof(int);
    
    print_array(a, n);
    
    heap_sort(a, n);
    
    print_array(a, n);
    
    
    return 0;
}
