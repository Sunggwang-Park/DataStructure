//
//  main.c
//  2016_UOS
//
//  Created by APPLE on 17/09/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
//2016년도 서울시립 문제 해답

//이진 트리
//노드 : 양의 정수 1개, 문자열 1개

typedef struct TreeNode{
    int data;
    char str[10];
    struct TreeNode *left,*right;
}TreeNode;


void inorder(TreeNode *root){
    if(root){
        printf("%d", root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

int find_max(TreeNode *root){
    
    int max = 0;
    int left;
    int right;
    
    if(root){
        if(root->data > max)
            max = root->data;
        left = find_max(root->left);
        if(left > max)
            max = left;
        right = find_max(root->right);
        if(right > max)
            max = right;
    }
    
    
    
    
    
    return max;
}

TreeNode *new_node(int a_data){
    TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
    if(new == NULL) {
        printf("메모리 할당 오류");
        return NULL;
    }
    new->data = a_data;
    new->left = NULL;
    new->right = NULL;
    
    return new;
}

void main(){
    TreeNode *root = new_node(10);
    
    root->left = new_node(15);
    root->right = new_node(20);
    
    root->left->left = new_node(7);
    root->left->right = new_node(30);
    
    root->right->left = new_node(16);
    root->right->right = new_node(22);
    
    int max = 0;
    max = find_max(root);
    
    printf("max = %d",max);
    
    
    
}

