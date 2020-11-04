//
//  main.c
//  Heapify
//
//  Created by APPLE on 06/08/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>

#define SWAP(a,b,tmp) (tmp = a, a = b, b = tmp)

void print_array(int a[], int n){
    
    
    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
    
    printf("\n");
}


void heapify(int a[], int n, int i){
    
    
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int temp = 0;
    
    if(left < n && a[largest] < a[left])
        largest = left;
    
    if(right < n && a[largest] < a[right])
        largest = right;
    
    if(largest != i){
        SWAP(a[i], a[largest], temp);
        
        heapify(a, n, largest);
    }
    
    
}


void heap_sort(int a[], int n){
    int temp = 0;
   
    
    //build max heap
    for(int i = n/2 -1; i >= 0; i--)
        heapify(a, n, i);
    
    print_array(a, n);
    
    
    //rearrange array
    for(int i = n -1; i >= 0; i--){
        //제일 큰 값(루트 노드)을 가장 마지막 요소와 교환 (제일 큰 값이 마지막 인덱스 값으로 됨)
        SWAP(a[0], a[i], temp);
        
        //루트 노드를 가장 큰값으로 변경
        heapify(a, i, 0);   //복기 할 때 틀렸던 부분 : heapify(a, n, 0) 이라고 했었음
    }
    
    
}








int main(int argc, const char * argv[]) {
    int arr[] = {4 , 7, 1, 35, 24, 15 ,26,3};
    int length = sizeof(arr) / sizeof(arr[0]);
    
    heap_sort(arr, length);
    
    print_array(arr, length);
    
    return 0;
}
