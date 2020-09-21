//
//  main.c
//  sparse_matrix_add2
//
//  Created by APPLE on 18/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3
#define MAX_TERMS 10

typedef struct{
    int row;    //요소의 행 위치
    int col;    // 열 위치
    int value;  // 값
}element;

typedef struct{
    element data[MAX_TERMS];
    int rows; //행의 개수
    int cols; //열의 개수
    int terms; //항의 개수
}SparseMatrix;

//희소 행렬 덧셈 함수 (0이 아닌 항목만 표시한 행렬의 덧셈)
//c = a + b
SparseMatrix sparse_matrix_add2(SparseMatrix a, SparseMatrix b)
{
    SparseMatrix c;
    int ca=0, cb=0, cc=0; //각 배열의 항목을 가리키는 인덱스
    //배열 a와 배열 b의 크기가 같은지 확인
    if( a.rows != b.rows || a.cols != b.cols){
        fprintf(stderr, "희소행렬 크기에러\n");
        exit(1);
    }
    c.rows = a.rows;
    c.cols = c.cols;
    c.terms = 0;
    
    while( ca < a.terms && cb < b.terms ){
        //각 항목의 순차적인 번호를 계산한다
        int inda = a.data[ca].row*a.cols + a.data[ca].col;
        int indb = b.data[cb].row*b.cols + b.data[cb].col;
        
        if( inda < indb) //a 배열 항목이 b 보다 앞에 있으면
            c.data[cc++] = a.data[ca++];
        
        else if( inda == indb){ //a와 b가 같은 위치
            if((a.data[ca].value+b.data[cb].value != 0)){
                c.data[cc].row = a.data[ca].row;
                c.data[cc].col = a.data[ca].col;
                c.data[cc++].value = a.data[ca++].value+b.data[cb++].value;
                
            }
            else{
                ca++;
                cb++;
            }
            
                
        }
        else    //b 배열 항목이 a보다 앞에 있음
            c.data[cc++] = b.data[cb++];
    }
    
    //배열 a나 b에 남아 있는 항들을 배열 c로 옮긴다.
    for(;ca < a.terms;)
        c.data[cc++] = a.data[ca++];
    for(;cb < b.terms;)
        c.data[cc++] = b.data[cb++];
   
    c.terms = cc;
    
    return  c;
    
}

// 희소행렬 출력
void print_matrix(SparseMatrix a[ROWS][COLS])
{
    int array[ROWS][COLS] = {0};
    SparseMatrix *temp = a;
    
    int r = 0,c = 0, i =0;
    for(r=0; r<ROWS; r++){
        for(c=0; c<COLS; c++){
            if(temp->data[i].row != r && temp ->data[i].col != c)
                 printf("%d ",array[r][c]);
            else
                printf("%d ", temp->data[i++].value);
               
        }
        printf("\n");
    }
    
    
}

int main(int argc, const char * argv[]) {
    
    SparseMatrix m1 = {{{1,1,2}, {2,2,7}}, 3,3,2};
    SparseMatrix m2 = {{{0,0,1}, {2,2,8}}, 3,3,2};
    SparseMatrix m3;
    
    m3 = sparse_matrix_add2(m1, m2);
    
    print_matrix(&m3);
    return 0;
}
