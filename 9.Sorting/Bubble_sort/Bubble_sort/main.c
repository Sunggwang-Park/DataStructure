//
//  main.c
//  Bubble_sort
//
//  Created by APPLE on 07/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_SIZE 100
#define SWAP(a,b,tmp) (tmp = a, a = b, b = tmp)
void bubble_sort(int list[], int n)
{
    int temp = 0;
    for (int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(list[j] > list[j+1])
                SWAP(list[j], list[j+1], temp);

 
}


//정렬된 배열일때 최적화된 버블 정렬
// bool 함수로 하나 더 추가하여 구현
void bubble_sort_optimazed(int list[], int n){
    int temp = 0;
    bool swapped;
    for(int i = 0; i < n-1; i++){
        swapped = false;
        for(int j = 0; j < n - i - 1; j++)
            if(list[j] > list[j+1]){
                SWAP(list[j], list[j+1], temp);
                swapped = true;
            }
        
        if(!swapped)
            break;

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
    
    bubble_sort(list, MAX_SIZE);
//    bubble_sort_optimazed(list, MAX_SIZE);
    
    print_array(list, MAX_SIZE);
    
    
    return 0;
}

