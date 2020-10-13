//
//  main.c
//  Threaded_binary_tree_book
//
//  Created by APPLE on 01/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//


//책에 나와 있는 스레드 이진트리 코드이다
//몇몇부분을 수정했으나 알고리즘은 책과 동일하다
//수정부분 : <stdbool.h> 를 포함하여 int is_threaded 를 bool 로 바꾸었다

//geeksforgeeks의 코드에 비해 복잡하다 이 사이트의 코드를 따로 구현해놓았다


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int element;
typedef struct TreeNode{
    element data;
    struct TreeNode *left, *right;
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



//이게 맞나 모르겠음
void all_tree_free(TreeNode *root)
{
    TreeNode *node = root;
    if(node == NULL) return;
    
    all_tree_free(node->left);
    all_tree_free(node->right);
    free(node);
}


TreeNode *find_successor(TreeNode *node)
{
    //p는 node의 오른쪽 포인터
    TreeNode *p = node->right;
    //만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
    if(p == NULL || node->is_threaded == true)
        return p;
    else{   //만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동
        while(p->left != NULL) p = p->left;
        return p;
    }
}

void thread_inorder(TreeNode *t)
{
    TreeNode *q = t;
    
    while (q->left != NULL) q = q->left; //가장 왼쪽 노드로 간다
    do{
        printf("%c", q->data);
        q = find_successor(q); //후속자 함수 호출
    }while(q != NULL);
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
    
    thread_inorder(root);
    
    free(root);
    
    
    return 0;
}
