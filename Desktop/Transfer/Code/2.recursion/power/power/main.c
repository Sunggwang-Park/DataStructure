//
//  main.c
//  power
//
//  Created by APPLE on 15/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <time.h>

//반복적인 거듭제곱 계산
double power_iter(double x, int n)
{

    double r = 1.0;
    for(int i=0; i<n; i++)
        r = r*x;
    return r;
}

//순환적인 거듭제곱 계산
double power_recur(double x, int n)
{
    printf("power_recur(%f,%d)\n", x,n);
    if(n == 0) return 1;
    else if (n%2 == 0)
        return power_recur(x*x, n/2);
    else return x*power_recur(x*x, (n-1)/2);
}



int main(int argc, const char * argv[]) {
   
    int a = 0, b = 0; //a : 정수  b : 지수
    clock_t start, finish;
    double duration = 0.0;
    
    printf("반복적인 거듭제곱 계산\n");
    printf("정수 :");
    scanf("%d",&a);
    printf("지수 :");
    scanf("%d",&b);

    start = clock();
    printf("result = %f \n",power_iter(a, b));
    finish = clock();
    printf("%f초 걸림", duration);
    
    printf("순환적인 거듭제곱 계산\n");
    printf("정수 :");
    scanf("%d",&a);
    printf("지수 :");
    scanf("%d",&b);
    
    printf("result = %f \n",power_recur(a, b));
    
    return 0;
}
