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

//test 1 삽입 함수 구현  - 성공
//
//  main.c
//  Threaded_binary_tree_geeks
//
//  Created by APPLE on 01/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//


//geeksforgeeks을 기반으로 만든 스레드 이진트리 코드임
//책보다 간결하다

//geeksforgeeks에 삽입, 삭제 코드가 있으니 한번 구현 바람

//test 1 삽입 함수 구현  - 성공
//test 2 삭제 함수 구현  - 성공

//완성된 코드

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int element;
typedef struct TreeNode{
    element data;
    struct TreeNode *left, *right;
    bool left_thread, right_thread;
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
    node->right_thread = node->left_thread = false;
    
    return node;
}

TreeNode *leftmost(TreeNode *node)
{
    if(node == NULL)
        return NULL;
    
    while (!node->left_thread && node->left != NULL)
        node = node->left;
    
    return node;
    
}

TreeNode *rightmost(TreeNode *node)
{
    if(node == NULL)
        return NULL;
    
    while (!node->right_thread && node->right != NULL)
        node = node->right;
    
    return node;
    
}

void inorder_thread(TreeNode *root)
{
    TreeNode *node = leftmost(root);
    
    while(node != NULL){
        
        printf("%d \n",node->data);
        
        if(node->right_thread){
            printf("스레드 실행\n");
            node = node->right;
        }
        else{
            printf("오른쪽 노드의 가장 왼쪽 자식노드 \n");
            node = leftmost(node->right);
        }
    }
}

void reverse_inorder_thread(TreeNode *root)
{
    TreeNode *node = rightmost(root);
    
    while(node != NULL){
        
        printf("%d \n",node->data);
        
        if(node->left_thread){
            printf("스레드 실행\n");
            node = node->left;
        }
        else{
            printf("왼쪽 노드의 가장 오른쪽 자식노드 \n");
            node = rightmost(node->left);
        }
    }
}

TreeNode *insert(TreeNode *root, element key)
{
    TreeNode *parent = NULL;
    TreeNode *temp = root;
    
    while (temp != NULL) {
        if (temp->data == key) {
            fprintf(stderr, "삽입 오류 - %d키는 이미 트리 안에 존재합니다\n",key);
            return root;
        }
        parent = temp;
        if (key < temp->data){
            if(temp->left_thread)
                temp = NULL;
            
            else temp = temp->left;
        }
        
        else{
            
            if(temp->right_thread)
                temp = NULL;
            else
                temp = temp->right;
        }
        
    }
    
    temp = new_node(key);
    if(parent == NULL)
        root = temp;
    
    
    else if(key < parent->data){
        
        temp->left = parent->left;
        temp->left_thread = true;
        temp->right_thread = true;
        temp->right = parent;
        
        parent->left = temp;
        parent->left_thread = false;
    }
    
    else {
        
        temp->left = parent;
        temp->left_thread = true;
        temp->right = parent->right;
        temp->right_thread = true;
        
        
        parent->right = temp;
        parent->right_thread = false;
    }
    
    return root;
}

TreeNode *insucc(TreeNode *ptr){        //ptr노드의 선행자를 찾는 함수
    if(ptr->right_thread)               //선행자 : ptr과 트리의 노드 중 제일 가깝고 큰 노드
        return ptr->right;
    
    ptr = ptr->right;
    
    while(!ptr->left_thread)
        ptr = ptr->left;
    
    return ptr;
}

TreeNode *inpred(TreeNode *ptr){        //ptr 노드의 후행자를 찾는 함수
    if(ptr->left_thread)                //후행자 : ptr과 트리의 노드 중 제일 가깝고 낮은 노드
        return ptr->left;
    
    ptr = ptr->left;
    while(!ptr->right_thread)
        ptr = ptr->right;
    
    return ptr;
}


//단말 노드 삭제
TreeNode *leafnode(TreeNode *root, TreeNode *parent, TreeNode *ptr){
    if(parent == NULL)
        root = NULL;
    
    else if (parent->left == ptr){
        parent->left = ptr->left;
        parent->left_thread = true;
    }
    else {
        parent->right = ptr->right;
        parent->right_thread = true;
    }
    
    free(ptr);
    return root;
}

//하나의 서브트리를 가지는 노드 삭제
TreeNode *onesubtree(TreeNode *root, TreeNode *parent, TreeNode *ptr)
{
    
    TreeNode *child;
    
    
    // Initialize child Node to be deleted has
    // left child.
    if (ptr->left_thread == false)
        child = ptr->left;
    
    // Node to be deleted has right child.
    else
        child = ptr->right;
    
    // Node to be deleted is root Node.
    if (parent == NULL)
        root = child;
    
    // Node is left child of its parent.
    else if (ptr == parent->left)
        parent->left = child;
    else
        parent->right = child;
    
    // Find successor and predecessor
    TreeNode *s = insucc(ptr);
    TreeNode *p = inpred(ptr);
    
    // If ptr has left subtree.
    if (!ptr->left_thread )
        p->right = s;
    
    // If ptr has right subtree.
    else
        s->left = p;
    
    
    free(ptr);
    return root;
}

//두개의 서브트리를 가지는 노드 삭제
//앞의 함수 두개를 사용 ( leafnode , onesubtree)
TreeNode *twosubtree(TreeNode *root, TreeNode *parent, TreeNode *ptr)
{
    TreeNode *succ_p = ptr;
    TreeNode *succ = ptr->right;
    
    while(!succ->left_thread){
        succ_p = succ;
        succ = succ->left;
    }
    
    ptr->data = succ->data;
    
    if(succ->left_thread && succ->right_thread)
        root = leafnode(root, succ_p, succ);
    else
        root = onesubtree(root, succ_p, succ);
    
    
    return root;
    
}

TreeNode *delete(TreeNode *root, int key){
    TreeNode *parent = NULL;
    TreeNode *temp = root;
    bool found = false;
    
    while (temp != NULL) {
        
        if(key == temp->data){
            found = !found;
            break;
        }
        parent = temp;
        if(key < temp->data) {
            if(temp->left_thread)
                break;
            
            else
                temp = temp->left;
        }
        else {
            if(temp->right_thread)
                break;
            else
                temp = temp->right;
        }
    }
    
    if(!found){
        fprintf(stderr, "%d키는 트리에 존재하지 않음\n",key);
        return root;
    }
    
    //삭제할 노드가 단말노드일때
    if(temp->left_thread  && temp->right_thread){
        root = leafnode(root, parent, temp);
    }
    //삭제할 노드가 하나의 서브 트리를 가질 때
    else if(temp->left_thread || temp->right_thread){
        root = onesubtree(root, parent, temp);
    }
    
    else {  //삭제할 노드가 두개의 서브트리를 가질 경우
        root = twosubtree(root, parent, temp);
        
    }
    
    return root;
    
    
}




int main(int argc, const char * argv[]) {
    
    TreeNode *root = NULL;
    root = insert(root, 50);
    
    
    //    int num;
    //    while(1){
    //        printf("삽입할 노드의 키 입력 : ");
    //
    //
    //    }
    int option;
    int num = 0;
    while(1){
        printf("\n1 : 삽입 , 2 : 삭제, 3 : 출력, 4 : 종료\n");
        scanf("%d",&option);
        
        if(option == 4){
            inorder_thread(root);
            break;
        }

        switch (option) {
            case 1:
                printf("키 입력 : ");
                scanf("%d", &num);
                insert(root, num);
                inorder_thread(root);
                break;
                
            case 2:
                printf("키 입력 : ");
                scanf("%d", &num);
                delete(root, num);
                inorder_thread(root);
                break;
                
                
            default:
                inorder_thread(root);
                break;
        }
    }
    
    
    
 
    
    
    
    return 0;
}
