//
//  main.c
//  BST
//
//  Created by APPLE on 31/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//
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
        else if(key < node->key)
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
TreeNode *insert_recur(TreeNode *root, element key)
{
    
    
    if(root == NULL) {
        //       printf("여기죠! %d\n" , key);
        return new_node(key);
    }
    
    if(root->key == key){
        fprintf(stderr, "%d키 값이 이미 트리에 존재함",key);
        return root;
    }
    
    
    else if(key < root->key){
        //      printf("왼쪽으로 갑니당 %d \n", key);
        root->left =  insert_recur(root->left, key);
        
    }
    else{
        //       printf("오른쪽으로 갑니당 %d \n", key);
        root->right =  insert_recur(root->right, key);
        
        
    }
    
    //    printf("마지막\n");
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


//책에 쓰여진 삭제 함수 - 반복적인 방법
void delete_node(TreeNode **root, int key)
{
    TreeNode *p, *child, *succ, *succ_p, *t;
    //p : 부모 노드  , t : 현재 노드  ,  succ : 후계자 노드
    //succ_p : 후계자 노드의 부모
    
    //key를 갖는 노드 t를 탐색, p는 t의 부모 노드
    p = NULL;
    t = *root;
    
    //key를 갖는 노드 t를 탐색한다
    while ( t != NULL && t->key != key) {
        p = t;
        t = ( key < p->key ) ? p->left : p->right;
    }
    
    //탐색이 종료된 시점에 t가 NULL이면 트리 안에 key가 없음
    if (t == NULL) {
        printf("key is not in the tree");
        return;
    }
    
    //첫번째 경우 : 단말 노드인 경우
    if (t->left == NULL && t->right == NULL) {
        if(p != NULL){
            //부모 노드의 자식 필드를 NULL로 만든다
            if(p->left == t)
                p->left = NULL;
            else
                p->right = NULL;
        }
        else    //만약 부모 노드가 NULL이면 삭제되는 노드가 루트
            *root = NULL;
        
    }
    
    //두번째 경우 : 하나의 자식만 가지는 경우
    else if(t->left == NULL || t->right == NULL){
        child = (t->left != NULL) ? t->left : t->right;
        if( p != NULL){
            //부모를 자식과 연결
            if(p->left == t)
                p->left = child;
            else
                p->right = child;
        }
        else        //만약 부모 노드가 NULL이면 삭제되는 노드가 루트
            *root = child;
        
    }
    
    //세번째 경우 : 두개의 자식을 가지는 경우
    else{
        //오른쪽 서브 트리에서 후계자를 찾는다
        succ_p = t;
        succ = t->right;
        //후계자를 찾아서 계속 왼쪽으로 이동한다
        while (succ->left != NULL) {
            succ_p = succ;
            succ = succ->left;
        }
        //후속자의 부모와 자식을 연결
        if(succ_p->left == succ)
            succ_p->left = succ->right;
        else
            succ_p->right = succ->right;    //while문이 실행 안된 상태
        
        //후속자가 가진 키 값을 현재 노드에 복사
        t->key = succ->key;
        //원래의 후속자 삭제
        t = succ;
    }
    
    free(t);
    
}


//Geeksforgeeks 에 쓰여진 delete 코드를 위한 노드의 오른쪽 서브트리 중 가장 작은 값의 노드 찾기 함수
TreeNode *minValueNode(TreeNode *node)
{
    TreeNode *current = node;
    
    while (current && current->left != NULL) {
        current = current->left;
    }
    
    return current;
}
//Geeksforgeeks 에 쓰여진 delete 코드 (순환적인 방법)
TreeNode *deleteNode_geeks(TreeNode *root, int key)
{
    
    
    //best case
    if(root == NULL) return root;
    
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if(key < root->key)
        root->left = deleteNode_geeks(root->left, key);
    
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if(key > root->key)
        root->right = deleteNode_geeks(root->right, key);
    
    // if key is same as root's key, then This is the node
    // to be deleted
    else{
        
        //node with only one child or no child
        if(root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        TreeNode *temp = minValueNode(root->right);
        
        root->key = temp->key;
        
        root->right = deleteNode_geeks(root->right, temp->key);
        
    }
    
    return root;
    
}



int main(int argc, const char * argv[]) {
    
    TreeNode *root = NULL;
    
    
    
    
    //geeks에 쓰여진 순환적인 삽입 함수
    root = insert_recur(root, 50);
    root = insert_recur(root, 20);
    root = insert_recur(root, 70);
    root = insert_recur(root, 10);
    root = insert_recur(root, 10);
    
    root = deleteNode_geeks(root, 70);
    root = deleteNode_geeks(root, 20);
    deleteNode_geeks(root,10);
    root = deleteNode_geeks(root, 50);
    
    
    
    printpreorder(root);
    
    
    
    return 0;
}
