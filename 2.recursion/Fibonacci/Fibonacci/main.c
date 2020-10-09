//
//  main.c
//  Fibonacci
//
//  Created by APPLE on 16/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>



//순환을 이용한 피보나치 수열 - 비효율적
//시간 복잡도 : 함수가 두개의 함수를 호출하는 이진 트리 형태이다
//즉 빅오 2의 n승이다
int fib_recur(int n)
{   //printf("fib_recur(%d)\n",n);
    if(n < 2) return n;
    
    else return (fib_recur(n-1) + fib_recur(n-2));
}


//반복을 이용한 피보나치 수열 - 효율적
//시간 복잡도 : n이 0과 1일 경우를 제외하면 n-1 번 반복되므로
//시간 복잡도는 빅오 n 이다
int fib_iter(int n)
{
    if(n < 2) return n;
    
    int i, tmp, current=1, last=0;
    for(i=2; i<=n; i++){
        tmp = current;
        current += last;
        last = tmp;
    }
    return current;
    
}

//Dynamic Programing 을 이용한 피보나치 수열
//시간복잡도는 빅오 n이다
int fib_dp(int n)
{
    int *f = (int *)malloc(sizeof(int) * (n+1));
    
    
    f[0] = 0;
    f[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        f[i] = f[i-2] + f[i-1];
    }
    
    return f[n];
    
}


int main(int argc, const char * argv[]) {
   
    int a=0;
   
    printf("순환을 이용한 피보나치 수열\n");
    printf("숫자입력 :");
    scanf("%d",&a);
    printf("result : %d\n",fib_recur(a));
    
    printf("반복을 이용한 피보나치 수열\n");
    printf("숫자입력 :");
    scanf("%d",&a);
    printf("result : %d\n",fib_iter(a));
    
    printf("동적프로그래밍을 이용한 피보나치 수열\n");
    printf("숫자입력 :");
    scanf("%d",&a);
    printf("result : %d\n",fib_dp(a));
    
    
    return 0;
}
