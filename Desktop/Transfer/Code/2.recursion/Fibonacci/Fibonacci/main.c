//
//  main.c
//  Fibonacci
//
//  Created by APPLE on 16/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>



//순환을 이용한 피보나치 수열 - 비효율적
int fib_recur(int n)
{   printf("fib_recur(%d)\n",n);
    if( n == 0 ) return 0;
    else if (n == 1) return 1;
    else return (fib_recur(n-1) + fib_recur(n-2));
}

//반복을 이용한 피보나치 수열 - 효율적
int fib_iter(int n)
{
    if(n < 2) return n;
    else{
        int i, tmp, current=1, last=0;
        for(i=2; i<=n; i++){
            tmp = current;
            current += last;
            last = tmp;
        }
        return current;
    }
}

//Dynamic Programing 을 이용한 피보나치 수열
int fib_dp(int n)
{
    int f[n + 1];
    
    
    f[0] = 0;
    f[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        f[i] = f[i-2] + f[i-1];
    }
    
    return f[n];
    
}


int main(int argc, const char * argv[]) {
   
    int a=0;
    int c =0;
  
    printf("%d",c);
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
