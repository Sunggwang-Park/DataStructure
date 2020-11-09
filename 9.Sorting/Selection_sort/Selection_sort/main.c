//
//  main.c
//  Selection_sort
//
//  Created by APPLE on 06/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

//Selection sort = 선택 정렬

#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 1000
#define change(a,b,tmp) (tmp = a, a = b, b = tmp)
void selection_sort(int a[], int n)
{
    int minpos = 0;
    int tmp = 0;
    for (int i = 0; i < n-1; i++) {
        minpos = i;
        for (int j = i+1; j < n; j++){
            if (a[j] < a[minpos])
                minpos = j;
        }
        change(a[i], a[minpos], tmp);
        
    }
    
}

//개선된 선택 정렬
void selection_sort_improvement(int a[], int n)
{
    int minpos = 0;
    int tmp = 0;
    for (int i = 0; i < n-1; i++) {
        minpos = i;
        for (int j = i+1; j < n; j++){
            if (a[j] < a[minpos])
                minpos = j;
        }
        //조건문을 사용하여 최솟값이 자기 자신이면 자리 이동을 하지 않는다
        if( i != minpos)
            change(a[i], a[minpos], tmp);
        
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
    
    int list[MAX_SIZE];
    for (int i = 0; i<MAX_SIZE; i++) {
        list[i] = rand()%MAX_SIZE;
    }
    
    selection_sort_improvement(list, MAX_SIZE);
    
    print_array(list, MAX_SIZE);
    
    
    return 0;
}
