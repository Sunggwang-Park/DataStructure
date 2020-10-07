//
//  main.c
//  BST_insertion
//
//  Created by APPLE on 02/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>


typedef int element;
typedef struct TreeNode{
    element key;
    struct TreeNode *left, *right;
}TreeNode;


void error(char *message)
{
    fprintf(stderr, "%s\n",message);
    exit(1);
}

//순환적인 탐색 함수 -> 책에 있는 코드임
//geeks에 있는 코드로바꾸기 ( 더 효율적임)
//현재 아래에 있는 코드는 geeks에 있는 코드임
TreeNode *search_recur(TreeNode *node, element key)
{
    if(node == NULL || node->key == key)
        return node;
    
    if(node->key > key)
        return search_recur(node->left, key);
    else
        return search_recur(node->right, key);
}

//반복적인 탐색 함수
TreeNode *search_iter(TreeNode *node, element key)
{
    while (node != NULL) {
        if(node->key == key)    return node;
        else if(node->key > key)
            node = node->left;
        else
            node = node->right;
    }
    return NULL;
}
TreeNode *new_node(element data)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if(node == NULL) error("트리노드 메모리 할당 오류");
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

//이진 트리 삽입함수 - 책에 있는 코드 (반복적인 삽입 함수)
void insert_node_iter_book(TreeNode **root, int key)
{
    TreeNode *p, *t;    //p - 부모노드 , t - 현재노드
    TreeNode *n;        //n - 새로운 노드
    
    p = NULL;
    t = *root;
    
    while (t != NULL) {
        if(t->key == key) return;
        p = t;
        if(t->key > key)
            t = t->left;
        else
            t = t->right;
    }
    
    n = (TreeNode *)malloc(sizeof(TreeNode));
    if(n == NULL) return;
    
    n->key = key;
    n->left = n->right = NULL;
    
    //부모 노드와 연결
    if(p != NULL)
        if(key < p->key)
            p->left = n;
        else p->right = n;
        else *root = n;
    
}

//Geeksforgeeks에 있는 코드 - 반복적인 삽입 함수
TreeNode *insert_iter_geeks(TreeNode *root, int key)
{
    TreeNode *new = new_node(key);
    
    TreeNode *p = root;
    
    TreeNode *t = NULL;
    
    while (p != NULL) {
        t = p;
        if(key < p->key)
            p = p->left;
        else
            p = p->right;
    }
    
    // If the root is NULL i.e the tree is empty
    // The new node is the root node
    if(t == NULL)
        t = new;
    else if (key < t->key)
        t->left = new;
    else
        t->right = new;
    
    return t;
}

//Geeksforgeeks 에 있는 순환적인 삽입 함수
TreeNode *insert_recur(TreeNode *root, int key)
{
    if(root == NULL) {
        printf("여기죠! %d\n" , key);
        return new_node(key);
    }
    
    if(key < root->key){
        printf("왼쪽으로 갑니당 %d \n", key);
        root->left =  insert_recur(root->left, key);
        
    }
    else{
        printf("오른쪽으로 갑니당 %d \n", key);
        root->right =  insert_recur(root->right, key);
        
        
    }
    
    printf("마지막\n");
    return root;
}

void printpreorder(TreeNode *root)
{
    if(root){
        printf("%d\n",root->key);
        printpreorder(root->left);
        printpreorder(root->right);
    }
    //printf("enter\n");
}



int main(int argc, const char * argv[]) {
    
    TreeNode *root = NULL;
    
    
    //책에 쓰여진 반복적인 삽입 함수
    //    insert_node_iter_book(&root, 10);
    //
    //    insert_node_iter_book(&root, 20);
    //    insert_node_iter_book(&root, 30);
    
    //geeks에 쓰여진 반복적인 삽입 함수
    //    root = insert_iter_geeks(root, 50);
    //    insert_iter_geeks(root, 20);
    //    insert_iter_geeks(root, 30);
    
    
    //geeks에 쓰여진 순환적인 삽입 함수
    root = insert_recur(root, 50);
    insert_recur(root, 20);
    insert_recur(root, 70);
    insert_recur(root, 10);
    
    
    
    printpreorder(root);
    
    
    
    return 0;
}
