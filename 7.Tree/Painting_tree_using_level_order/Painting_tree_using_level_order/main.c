//
//  main.c
//  Painting_tree_using_level_order
//
//  Created by APPLE on 29/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define max(a,b) ((a > b)? a : b)

typedef int item;


typedef struct TreeNode{
    item data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

typedef TreeNode *element;

void error(char *message)
{
    fprintf(stderr, "%s\n",message);
    exit(1);
}

TreeNode *new_node(item data)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if(node == NULL) error("트리노드 메모리 할당 오류");
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}



//이게 맞나 모르겠음
void all_tree_free(TreeNode *root)
{
    TreeNode *node = root;
    if(node == NULL) return;
    
    all_tree_free(node->left);
    all_tree_free(node->right);
    free(node);
}

void printpreorder(TreeNode *root)
{
    if(root){
        printf("%d\n",root->data);
        printpreorder(root->left);
        printpreorder(root->right);
    }
    printf("\t\tenter\n");
}


//중위 순회
void printinorder(TreeNode *root)
{
    if(root){
        printinorder(root->left);
        printf("%d ",root->data);
        printinorder(root->right);
    }
    printf("\n");
}


//후위 순회
void printpostorder(TreeNode *root)
{
    if(root){
        printpostorder(root->left);
        printpostorder(root->right);
        printf("%d ",root->data);
    }
    printf("\n");
}


typedef struct QueueNode{
    element item;
    struct QueueNode *link;
}QueueNode;
typedef struct{
    QueueNode *front, *rear;
}QueueType;


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


void level_order(TreeNode *root)
{
    QueueType q;
    
    init(&q);
    if( root == NULL) return;
    enqueue(&q, root);
    while (!is_empty(&q)) {
        root = dequeue(&q);
        printf("%d ", root->data);
        if(root->left)
            enqueue(&q, root->left);
        if(root->right)
            enqueue(&q, root->right);
    }
}

int power (int x, int n)
{
    if (n == 0) {
        return 1;
    }
    else if (n % 2 == 0) {
        return power(x*x, n/2);
    }
    else return x*power(x*x, (n-1)/2);
}

void level_order_Tree(TreeNode *root , int height)
{
    QueueType q;
    int count = 1;
    
    init(&q);
    if( root == NULL) return;
    enqueue(&q, root);
    for(int i = 1; i <= height; i++) {
        while(count < power(2, i)){
        root = dequeue(&q);
        for (int j = 0; j < height-i; j++) {
            printf("\t");
        }
        printf("%d\t", root->data);
            if (count == power(2, i-1) && i > 2) {
                printf("   ");
            }
        count++;
        
        if(root->left)
            enqueue(&q, root->left);
        if(root->right){
            enqueue(&q, root->right);
            
        }
        }
        //height--;
        printf("\n");
    }
}

int get_height(TreeNode *root)
{
    int height = 0;
    
    if( root != NULL)
        height = 1 + max(get_height(root->left), get_height(root->right));
    
    
    
    return height;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode *root = new_node(10);
    
    root->left = new_node(20);
    root->right = new_node(30);
    
    root->left->left = new_node(40);
    root->left->right = new_node(50);
    
    root->right->left = new_node(60);
    root->right->right = new_node(70);
    
    root->left->left->left = new_node(80);
    root->left->left->right = new_node(90);
    
    
    level_order_Tree(root, get_height(root));
    
 //   printf("%d", get_height(root));
    
    
    
    
    return 0;
}
