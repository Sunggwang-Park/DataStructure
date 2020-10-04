//
//  main.c
//  BInary_tree_operation
//
//  Created by APPLE on 01/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a>b)? a : b)

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

//노드의 개수 구하기
int get_node_count(TreeNode *node)
{
    int count = 0;
    if (node != NULL)
        count = 1 + get_node_count(node->left) + get_node_count(node->right);
    
    return count;
    
}

//단말 노드 개수 구하기
int get_leaf_count(TreeNode *node)
{
    int count = 0;
    if(node != NULL){
        if(node->left == NULL && node->right == NULL) return 1;
        else count = get_leaf_count(node->left) + get_leaf_count(node->right);
    }
    return count;
    
}

int get_height(TreeNode *node)
{
    int height = 0;
    if (node != NULL) {
        height = 1 + max(get_height(node->left), get_height(node->right));
    }
    return height;
}

int main(int argc, const char * argv[]) {
    
    TreeNode *root = new_node(10);
    
    root->left = new_node(20);
    root->right = new_node(30);
    
    root->left->left = new_node(40);
    root->left->right = new_node(50);
    
    root->right->left = new_node(60);
    root->right->right = new_node(70);
    
    root->left->left->left = new_node(80);
    root->left->left->right = new_node(90);
    
    printf("노드의 개수 : %d\n", get_node_count(root));
    printf("단말노드의 개수 : %d\n", get_leaf_count(root));
    printf("이진트리의 높이 : %d\n", get_height(root));
    
    return 0;
}
