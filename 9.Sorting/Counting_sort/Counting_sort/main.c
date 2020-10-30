//
//  main.c
//  Counting sort
//
//  Created by APPLE on 06/10/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define RANGE 10



void counting_sort(int list[], int size){
    int count[RANGE] = {0};
    int *sorted = (int *)malloc(sizeof(int) * size);
  
    int i;
    for (i = 0; i < size; i++)
        ++count[list[i]];
    
    for (i = 1; i < RANGE; i++)
        count[i] += count[i-1];
    
    printf("\n");
    for (i = 0; i < RANGE; i++)
        printf("%d ",i);
    
    
    printf("\n");
    for (i = 0; i < RANGE; i++)
        printf("%d ",count[i]);
    
    printf("\n");
    
    for (i = 0; i < size; i++){
        sorted[count[list[i]] - 1] = list[i];
        --count[list[i]];
    }
    
    // stable 하게 정렬하기
//    for (i = size-1; i >= 0; i--) {
//        sorted[count[list[i]] - 1] = list[i];
//        --count[list[i]];
//    }
    
    for (i = 0; i < size; i++)
        list[i] = sorted[i];
    

}


int main() {
    
    int arr[] = {5, 2, 4, 1, 2, 6, 9, 3, 4, 8, 8};
    int size = sizeof(arr)/sizeof(int);
    
    for (int i = 0; i < size; i++)
        printf("%d ",arr[i]);
    
    counting_sort(arr, size);
    
    printf("\n");
    for (int i = 0; i < size; i++)
        printf("%d ",arr[i]);
    
    printf("\n");
    
    return 0;
}
