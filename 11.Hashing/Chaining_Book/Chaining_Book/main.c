//
//  main.c
//  Chaining_Book
//
//  Created by APPLE on 20/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//
//

//책에 쓰여진 체이닝
//삭제함수를 추가해보았다


#include <stdio.h>
#include <stdlib.h>

#define equal(e1, e2) (!strcmp(e1.key, e2.key))
#define KEY_SIZE 10 //탐색 키의 최대 길이
#define TABLE_SIZE 13   //해싱 테이블의 길이 = 소수

typedef struct{
    char key[KEY_SIZE];
    //다른 필요한 필드들
}element;

typedef struct ListNode
{
    element item;
    struct ListNode *link;
}ListNode;


int transform(char *key)
{
    int sum = 0;
    while(*key)
        sum += *key++;
    
    return sum;
}

int hash_function(char *key)
{
    return transform(key) % TABLE_SIZE;
}


//체이닝을 이용하여 테이블에 키를 삽입
void hash_chain_add(element item, ListNode *ht[])
{
    int hash_value = hash_function(item.key);
    
    ListNode *node_before = NULL;   //이전 노드
    ListNode *node = ht[hash_value]; //현재 노드
    for (; node; node_before = node, node = node->link) {
        if (equal(node->item, item)) {
            fprintf(stderr, "이미 탐색 키가 저장되어 있음");
            return;
        }
    }
    ListNode *new = (ListNode *)malloc(sizeof(ListNode));
    if(new == NULL){
        fprintf(stderr, "메모리 할당 오류");
        return;
    }
    new->item = item; 
    new->link = NULL;
    if(node_before)     //기존의 연결 리스트가 있으면
        node_before->link = new;
    else                //기존의 연결 리스트가 없으면
        ht[hash_value] = new;
}


void hash_chain_delete(element item, ListNode *ht[])
{
    int hash_value = hash_function(item.key);
    ListNode *node_before = NULL;   //이전 노드
    ListNode *node = ht[hash_value];    // 현재 노드
    for (; node; node_before = node, node = node->link) {
        if(equal(item, node->item)){
            printf("%s 삭제\n",node->item.key);
            if(node_before)
                node_before->link = node->link;
            else
                ht[hash_value] = node->link;
            free(node);
            return;
        }
    }
    printf("%s가 존재하지 않음\n",item.key);
    
}

//체이닝을 이용하여 테이블에 저장된 키를 탐색
void hash_chain_find(element item, ListNode *ht[])
{
    ListNode *node;
    
    int hash_value = hash_function(item.key);
    for(node = ht[hash_value]; node; node = node->link){
        if(equal(node->item, item)){
            printf("키를 찾았음 / 위치 :%d\n",hash_value);
            return;
        }
    }
    printf("키를 찾지못했음\n");
}


void hash_lp_print(ListNode *ht[])
{
    ListNode *temp;
    
    for(int i = 0; i < TABLE_SIZE; i++){

        printf("[%d]  ", i );
        for(temp = ht[i]; temp; temp = temp->link)
            printf(" -> %s",temp->item.key);
        printf("\n");
        
    }
}

void init_table(ListNode *ht[])
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht[i] = NULL;
    }
}


int main(int argc, const char * argv[]) {
    element tmp;
    ListNode *hash_table[TABLE_SIZE]; //해시 테이블
    init_table(hash_table);
    int op;
    while (1) {
        printf("원하는 연산을 입력하시오 ( 0 = 입력, 1 = 탐색, 2 = 삭제, 3 = 종료)\n");
        scanf("%d",&op);
        if(op == 3) break;
        printf("키를 입력하시오 = ");
        scanf("%s",tmp.key);
        if (op == 0)
            hash_chain_add(tmp, hash_table);
        else if(op == 1)
            hash_chain_find(tmp, hash_table);
        else
            hash_chain_delete(tmp, hash_table);
      
        hash_lp_print(hash_table);
        
    }
    return 0;
}
