//
//  main.c
//  Factorial
//
//  Created by APPLE on 27/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//순환을 이용한 팩토리얼 계산
int factorial_recur(int n)
{
    if(n <= 1) return 1 ;
    else return (n *factorial_recur(n-1));
    
// single line to find factorial from Geeks
//    return (n == 1 || n == 0) ? 1 : n * factorial_recur(n - 1);
}


//반복을 이용한 팩토리얼 계산
int factorial_iter(int n){
    int fact = 1;
    
    while(n > 0){
        fact *= n;
        n--;
    }
    
    return fact;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    unsigned int a = 0;
    clock_t start, finish;
    double duration;
    
    
    printf("순환을 이용한 팩토리얼\n");
    printf("숫자 입력: ");
    scanf("%d",&a);
    start = clock();
    printf("%d! = %d\n",a,factorial_recur(a));
    finish = clock();
    duration = (double)(finish-start) / CLOCKS_PER_SEC;
    printf("%f초 걸림\n",duration);
    
    printf("반복을 이용한 팩토리얼\n");
    printf("숫자 입력: ");
    scanf("%d", &a);
    start = clock();
    printf("%d! = %d\n",a, factorial_iter(a));
    finish = clock();
    duration = (double)(finish-start) / CLOCKS_PER_SEC;
    printf("%f초 걸림\n",duration);
    
    return 0;
}
