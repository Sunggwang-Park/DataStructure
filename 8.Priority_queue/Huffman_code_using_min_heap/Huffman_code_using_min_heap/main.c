//
//  main.c
//  Huffman_code_using_min_heap
//
//  Created by APPLE on 06/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//



//최소 히프 트리를 사용하여 허프만 코드를 구하는 함수

//인터넷에 찾아보니 허프만 코드를 출력을 하려면 DFS 방법을 사용해야 하는 것 같다
//lab 이 1회독 끝나면 다시 시도해야됨


#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100
typedef struct TreeNode {
    int weight;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

typedef struct{
    TreeNode *ptree;
    int key;
}element;

typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

//초기화 함수
void init(HeapType *h)
{
    h->heap_size = 0;
}

//삽입 함수 - 최소 트리
void insert_min_heap(HeapType *h, element item)
{
    int i = ++(h->heap_size);
    
    if(i > MAX_ELEMENT){
        printf("삽입 오류 - 포화 히프");
        return;
    }
    
    
    while (i != 1 && h->heap[i].key < h->heap[i/2].key) {

        h->heap[i] = h->heap[i/2];
        i /= 2;
        
    }
    h->heap[i] = item;
        
   
}

//삭제 함수 - 책을 참고하여 내가 만든 코드 (parent , child 변수가 없다)
element delete_min_heap(HeapType *h)
{
    element min = h->heap[1];
    element last = h->heap[(h->heap_size)--];
    
    
    int i = 2;
    while (i <= h->heap_size) {
       
        if( i < h->heap_size &&  h->heap[i].key > h->heap[i+1].key)
            i++;
        if(last.key <= h->heap[i].key)
            break;
        
        //부모노드를 가장 작은 자식노드로 붙여넣기
        h->heap[i/2] = h->heap[i];
        i *= 2;
      
        
    }
    h->heap[i/2] = last;
    
    
    return min;
}

//책에 있는 함수
element delete_min_heap_book(HeapType *h)
{
    int parent, child;
    element min, last;
    
    min = h->heap[1];
    last = h->heap[(h->heap_size)--];
    parent = 1;
    child =2;
    
    while (child <= h->heap_size) {
        
        if( child < h->heap_size &&  h->heap[child].key > h->heap[child+1].key)
            child++;
        if(last.key <= h->heap[child].key)
            break;
        
        //부모노드를 가장 작은 자식노드로 붙여넣기
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
        
    }
    h->heap[parent] = last;
    
    
    return min;
}

//sanfoundry 사이트에 있는 삭제 함수
element delete_min_heap_san(HeapType *h)
{
    
    element minElement, lastElement;
    int child ,now;
    
    minElement = h->heap[1];
    lastElement = h->heap[(h->heap_size)--];
    
    for (now = 1; now * 2 <= h->heap_size; now = child) {
        child = now * 2;
        
        if (child != h->heap_size && h->heap[child + 1].key < h->heap[child].key)
            child++;
        
        if(lastElement.key > h->heap[child].key)
            h->heap[now] = h->heap[child];
        else
            break;
        
    }
    h->heap[now] = lastElement;
    return minElement;

}

//이진 트리 생성 함수
TreeNode *make_tree(TreeNode *left, TreeNode *right)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if(node == NULL){
        fprintf(stderr, "메모리 에러");
        return node;
    }
    node->left = left;
    node->right = right;
    
    return node;
        
}

//이진 트리 제거 함수
void destroy_tree(TreeNode *root)
{
    if(root == NULL) return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

//허프만 코드 생성 함수
void huffman_tree(int freq[], int n)
{
    int i = 0;
    TreeNode *node, *x;
    HeapType heap;
    element e, e1, e2;
    
    init(&heap);
    for (i = 0; i<n; i++) {
        node = make_tree(NULL, NULL);
        e.key = node->weight = freq[i];
        e.ptree = node;
        insert_min_heap(&heap, e);
    }
    for (i = 1; i<n; i++) {
        //최솟값을 가지는 두 개의 노드를 삭제
        e1 = delete_min_heap(&heap);
        e2 = delete_min_heap(&heap);
        //두 개의 노드를 합친다
        x = make_tree(e1.ptree, e2.ptree);
        e.key = x->weight = e1.key + e2.key;
        e.ptree = x;
        insert_min_heap(&heap, e);
    }
    e = delete_min_heap(&heap); // 최종 트리
    
    
    
    destroy_tree(e.ptree);
    
}




int main(int argc, const char * argv[]) {
    int freq[] = {15, 12, 8, 6, 4};
    huffman_tree(freq, 5);
    return 0;
}
