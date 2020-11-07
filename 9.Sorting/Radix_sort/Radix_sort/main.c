//
//  main.c
//  Radix_sort
//
//  Created by APPLE on 10/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//
//기수 정렬은 O(dn)의 시간복잡도를 가지는데 d는 데이터의 자릿수로 대부분 d < 4이다. 다만 문제는 기수 정렬은 제자리 정렬이 아니라는 점이다. 다시말해, 추가적인 메모리 공간이 필요하다. 하지만 기수 정렬의 빠른 성질 때문에 메모리가 크게 소비되지 않느다면 별 문제를 일으키지 않는다. 다만 한가지 피할 수 없는 단점은 정렬할 수 있는 데이터타입이 한정된다는 것이다. 기수정렬을 사용하려면 키들이 동일한 숫자나 문자열로 구성되어 있어야 한다.
//기수 정렬의 시간복잡도는 O(dn)이다. 시간복잡도가 d(자리수)에 비례하기 때문에 기수 정렬의 수행시간은 정수와 관련이 깊다. 그러나 일반적으로 컴퓨터의 정수의 크기는 제한적이다. 32비트 컴퓨터의 경우 대개 10개 정도의 자리수만 가지게 된다. 따라서 일반적으로 d는 n에 비하여 아주 작은 수가 되므로 기수 정렬은 O(n)이라고 하여도 큰 무리가 없다.
//출처 - https://proneer.tistory.com/entry/Sort-%EA%B8%B0%EC%88%98-%EC%A0%95%EB%A0%ACRadix-Sort
//책에 있는 버전만 구현되어있음 - 구현하였음(2020/10/7/Wed)
//외국사이트들의 코드들은 책의 버전과 많이다름


//외국 코드 : 큐를 이용하지 않고 카운팅 정렬을 사용함


//책의 코드로도 다양한 자릿수의 수 기수 정렬 가능 ( DIGITS 상수를 가장 큰 자릿수로 고치면 됨)

//책의 코드로 외우는게 나을 듯 !   -> 카운팅 정렬을 사용한 외국 코드가 더 나은 듯(2020/10/7/Wed)
// 하지만 외국 코드도 구현 바람 ( 카운팅 정렬 사용, 비트연산 사용)

#define BUCKETS 10
#define DIGITS 4
#define MAX_SIZE 10

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode{
    element item;
    struct QueueNode *link;
}QueueNode;
typedef struct{
    QueueNode *front, *rear;
}QueueType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//초기화 함수
void init(QueueType *q)
{
    q->front = q->rear = NULL;
    
}

//공백 함수
int is_empty(QueueType *q)
{
    return q->front == NULL;
    
}

//삽입 함수
void enqueue(QueueType *q, element item)
{
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    if (temp == NULL) {
        error("메모리 할당 오류 - 삽입할 노드의 메모리가 할당 되지 않습니다");
    }
    temp->item = item;
    temp->link = NULL;
    if(is_empty(q)){       //공백 큐일때
        q->front = temp;
        q->rear = temp;
    }
    else{                   //큐가 공백이 아니면
        q->rear->link = temp;
        q->rear = temp;
    }
}

element dequeue(QueueType *q)
{
    if(is_empty(q))
        error("삭제 함수 오류 - 큐가 공백상태입니다");
    
    QueueNode *temp = q->front;
    q->front = q->front->link;
    
    element item = temp->item;
    if (q->front==NULL) {       //공백상태
        q->rear = NULL;
    }
    free(temp);                 //노드 메모리 해제
    return item;                //데이터 반환
    
}

element peek(QueueType *q)
{
    if(is_empty(q))
        error("미리보기 오류 - 큐가 공백상태입니다");
    return q->front->item;
}




//책에 있는 기수 정렬
void radix_sort_book(int list[], int n)
{
    int i, b, d, factor = 1;
    QueueType queues[BUCKETS];
    
    //BUCKETS 10
    for(b = 0; b < BUCKETS; b++) init(&queues[b]);  //큐들의 초기화
    
    //DIGITS 4 (가장 큰 수의 자릿수)
    //n = MAX_SIZE(10)
    for (d = 0; d < DIGITS; d++) {
        for(i = 0; i < n; i++)              //데이터들을 자릿수에 따라 큐에 입력(가장 작은 자릿수 먼저)
            enqueue(&queues[(list[i] / factor) % 10], list[i]);

        for(b = i = 0; b < BUCKETS; b++)    //버켓에서 꺼내어 list로 합친다
            while( !is_empty(&queues[b]))
                list[i++] = dequeue(&queues[b]);
        factor *= 10;       //그 다음 자릿수로 간다
    }
}

//-----------------------------------------------------
//Geeks 에 있는 카운팅 정렬을 subrutine 으로 활용한 radix sort
int getMax(int list[], int size){
    int max = list[0];
    
    for (int i = 1; i < size; i++)
        if (list[i] > max)
            max = list[i];
    
    return max;
    
}

void counting_sort(int list[], int size, int exp){
    int sorted[size], i;    //sorted[] : 자릿수에 따라 정렬된 상태로 sorted에 저장
    int count[10] = {0};          //count[] : 카운팅된 인덱스를 이 배열에 표시
    
    
    //count 배열에 숫자의 출현 빈도 표시
    for (i = 0; i < size; i++)
        ++count[(list[i] / exp) % 10];
    
    //바로 전의 숫자와 더함 (sorted[]에 겹치지 않도록 배치될 index를 의미함)
    for (i = 1; i < 10; i++)
        count[i] += count[i-1];
    
    //뒤에서부터 앞으로 정렬하면 stable하게 정렬이 됨
    //radix sort가 안정되게 정렬되지 않으면 제일 큰 자릿수를 제외한 자릿수들의 순서가 내림차순, 즉 역으로 된다
    for (i = size-1; i >= 0; i--) {
        sorted[count[(list[i] / exp) % 10] - 1] = list[i];
        --count[(list[i] / exp) % 10];
    }
    
    
    //sorted배열을 list로 옮긴다
    for (i = 0; i < size; i++)
        list[i] = sorted[i];
    
    
    
}

void radix_sort_geeks(int list[], int size){
    
    int max = getMax(list, size);   //배열의 가장 큰 수를 max에 저장한다
    
    //exp : 자릿수를 구하기 위한 정수
    //max / exp > 0;  => max/exp의 값이 0.XXX 이 되면(ex. 525/1000) int값이므로 0이 되어서 for문이 중지된다.
    //즉, for문을 정렬하려는 배열의 가장 큰 값이 가지는 자릿수 만큼 반복한다. 예를 들어, max가 3자리의 수인 525 이면 for문이 3번 반복되고 4번째가 실행되기 전에 중지된다.
    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(list, size, exp);
    }
    
}




void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int list[] = {5 ,4, 2, 9, 8, 234, 543, 5251, 9122, 2, 63, 89};
//    int list[MAX_SIZE];
//    for (int i = 0; i<MAX_SIZE; i++) {
//        list[i] = rand()%MAX_SIZE;
//    }

//    radix_sort_book(list, MAX_SIZE);
    int size = sizeof(list)/sizeof(list[0]);
    radix_sort_geeks(list, size);
    
    print_array(list, size);
    
    return 0;
}
