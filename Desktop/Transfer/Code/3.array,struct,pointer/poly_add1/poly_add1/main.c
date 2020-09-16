//
//  main.c
//  poly_add1
//
//  Created by APPLE on 16/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>


#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

//다항식 구조체 타입선언
typedef struct{
    int degree;             //다항식의 차수
    float coef[MAX_DEGREE]; //다항식의 계수
}polynomial;


//다항식 더하기 함수
//C = A + B
polynomial poly_add1(polynomial A, polynomial B)
{
    polynomial C;               //결과 다항식
    int Apos=0, Bpos=0, Cpos=0; //배열 인덱스 변수
    int degree_a = A.degree;    //두 다항식의 항 비교 ,차례때마다 1씩 감소
    int degree_b = B.degree;
    C.degree = MAX(A.degree, B.degree);
    
//    C.degree = MAX(A.degree, B.degree);  //결과 다항식 차수
    
    while(Apos<=A.degree && Bpos<=B.degree){
        if(degree_a > degree_b){
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        }
        else if(degree_a == degree_b){
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--; degree_b--;
        }
        else{
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}


int main(int argc, const char * argv[]) {
    
    polynomial a = {5, {3,6,0,0,0,10}};
    polynomial b = {4, {7,0,5,0,1}};
    
    polynomial c;
    c = poly_add1(a, b);
    return 0;
}
