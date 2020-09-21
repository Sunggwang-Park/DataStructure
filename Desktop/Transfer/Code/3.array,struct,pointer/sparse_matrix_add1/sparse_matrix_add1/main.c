//
//  main.c
//  sparse_matrix_add1
//
//  Created by APPLE on 18/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#define ROWS 3  //행의 개수
#define COLS 3  //열의 개수

//희소 행렬 덧셈 함수 - 일반적인 덧셈
//똑같은 행과 열의 자리에 있는 두 값을 더함
// C = A + B
void sparse_matrix_add1(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS])
{
    int r = 0,c = 0;
    for(r=0; r<ROWS; r++)
        for(c=0; c<COLS; c++)
            C[r][c] = A[r][c] + B[r][c];
}

void print_matrix(int A[ROWS][COLS])
{
    int r = 0,c = 0;
    for(r=0; r<ROWS; r++){
        for(c=0; c<COLS; c++)
            printf("%d ",A[r][c]);
        printf("\n");
    }
    
    
}

int main(int argc, const char * argv[]) {
    
    int array1[ROWS][COLS] = { { 2,3,0 }, { 8,9,1 }, { 7,0,5 }};
    int array2[ROWS][COLS] = { { 4,5,0 }, { 1,1,2 }, { 3,2,1 }};
    
    int array3[ROWS][COLS];
    
   // print_matrix(array1);
    
    sparse_matrix_add1(array1, array2, array3);
    print_matrix(array3);
    
    return 0;
}
