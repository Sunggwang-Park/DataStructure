//
//  main.c
//  Binary_tree_traverse
//
//  Created by APPLE on 29/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int element;

typedef struct TreeNode{
    element data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

void error(char *message)
{
    fprintf(stderr, "%s\n",message);
    exit(1);
}

TreeNode *new_node(element data)
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


int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode *root = new_node(10);
    
    root->left = new_node(20);
    root->right = new_node(30);
    
    root->left->left = new_node(40);
    root->left->right = new_node(50);
    
    root->right->left = new_node(60);
    root->right->right = new_node(70);
    
    printf("-- preorder --\n");
    printpreorder(root);
    
    printf("-- inorder --\n");
    printinorder(root);
    
    printf("-- postorder --\n");
    printpostorder(root);
    
    

    
    return 0;
}
