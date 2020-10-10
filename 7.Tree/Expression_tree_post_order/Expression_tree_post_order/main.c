//
//  main.c
//  Expression_tree_post_order
//
//  Created by APPLE on 30/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
    element data;
    struct TreeNode *left, *right;
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
    if(root == NULL) return;
    
    all_tree_free(root->left);
    all_tree_free(root->right);
    free(root);
}

int evaluate(TreeNode *root)
{
    if( root == NULL) return 0;
    if( root->left == NULL && root->right == NULL)
        return root->data;
    else{
        int op1 = evaluate(root->left);
        int op2 = evaluate(root->right);
        switch (root->data) {
            case '+':
                return op1+op2;
            case '-':
                return op1-op2;
            case '*':
                return op1*op2;
            case '/':
                return op1/op2;

            
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    TreeNode *root = new_node('+');
    root->left = new_node('*');
    root->right = new_node('+');
    
    root->left->left = new_node(2);
    root->left->right = new_node(4);
    
    root->right->left = new_node(16);
    root->right->right = new_node(25);
    
    
    
    
    printf("%d\n", evaluate(root));
    
    all_tree_free(root);
    
    return 0;
}
