//
//  main.c
//  Threaded_binary_tree_geeks
//
//  Created by APPLE on 01/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//


//geeksforgeeks에서 따온 스레드 이진트리 코드임
//책보다 간결하다
//아직 삽입과 삭제는 없음 (책에는 없는 기능)
//geeksforgeeks에 삽입, 삭제 코드가 있으니 한번 구현 바람


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int element;
typedef struct TreeNode{
    element data;
    struct TreeNode *left,*right;
    bool is_threaded;
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
    node->is_threaded = false;
    
    return node;
}

TreeNode *leftmost(TreeNode *node)
{
    if(node == NULL)
        return NULL;
    
    while (node->left != NULL)
        node = node->left;
    
    return node;
        
}

void inorder_thread(TreeNode *root)
{
    TreeNode *node = leftmost(root);
    
    while(node != NULL){
        
        printf("%c ",node->data);
        
        if(node->is_threaded)
            node = node->right;
        else
            node = leftmost(node->right);
    }
}


int main(int argc, const char * argv[]) {
    
    TreeNode *root = new_node('D');
    
    root->left = new_node('B');
    root->right = new_node('F');
    
    root->left->left = new_node('A');
    root->left->right = new_node('C');
    
    root->right->left = new_node('E');
    root->right->right = new_node('G');
    
    root->left->left->is_threaded = true;
    root->left->left->right = root->left;
    
    root->left->right->is_threaded = true;
    root->left->right->right = root;
    
    root->right->left->is_threaded = true;
    root->right->left->right = root->right;
    
    inorder_thread(root);
    
    free(root);
    
    return 0;
}
