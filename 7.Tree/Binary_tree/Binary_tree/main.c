//
//  main.c
//  Binary_tree
//
//  Created by APPLE on 29/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

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




void all_tree_free(TreeNode *root)
{
    TreeNode *node = root;
    if(node == NULL) return;
   
    all_tree_free(node->left);
    all_tree_free(node->right);
    free(node);
}



int main(int argc, const char * argv[]) {
    
    TreeNode *n1, *n2, *n3;
    n1 = new_node(10);
    n2 = new_node(20);
    n3 = new_node(30);
    
    n1->left = n2;
    n1->right = n3;
    
    all_tree_free(n1);
    
    
    
    
    
    return 0;
}
