//
//  main.c
//  Quick_sort_Median_of_three
//
//  Created by APPLE on 03/11/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//
#include <stdio.h>

int quick_median = 0;
int quick = 0;

#define SWAP(a,b,tmp) tmp = a, a = b, b = tmp



//from myself
//int median(int list[],int left, int right){
//    int mid = (left+right)/2;
//    int median_index;
//    int most_index;
//
//    most_index = (list[left] > list[mid]) ? left : mid;
//    median_index = (most_index == left) ? mid : left;
//
//
//    if(list[most_index] < list[right]){
//        median_index = most_index;
//    }
//    else
//        median_index = (list[median_index] > list[right])? median_index : right;
//
//
//    return median_index;
//
//
//}

//from stack overflow
int median(int list[],int left, int right){
    int mid = (left+right)/2;
    
    if((list[left] > list[mid]) != (list[left] > list[right]))
        return left;
    else if( (list[mid] > list[left]) != (list[mid] > list[right]))
        return mid;
    else
        return right;
    
    
}

int partition_median(int list[], int left, int right){
    int pivot_index = median(list, left, right);
    int pivot = list[pivot_index];
    int temp;
    SWAP(list[left], list[pivot_index], temp);
    int i = left+1;
    int j;

    for(j = i; i <= right; i++)
        if(list[i] < pivot){
            SWAP(list[i],list[j],temp);
            j++;
        }

    SWAP(list[left],list[j-1],temp);
    return j-1;

}

int partition(int list[], int left, int right){
    int pivot = list[left];
    int i = left+1;
    int temp;
    int j;

    for(j = i; i <= right; i++)
        if(list[i] < pivot){
            SWAP(list[i],list[j],temp);
            j++;
        }

    SWAP(list[left],list[j-1],temp);
    return j-1;

}


void quick_sort(int list[], int left, int right){
    quick++;
    if(left < right){
        int middle = partition(list,left, right);
        quick_sort(list,left, middle-1);
        quick_sort(list, middle+1, right);
    }
}
void quick_sort_median(int list[], int left, int right){
    quick_median++;
    if(left < right){
        int middle = partition_median(list,left, right);
        quick_sort_median(list,left, middle-1);
        quick_sort_median(list, middle+1, right);
    }
}

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
    quick_sort(a, 0, 17);
    quick_sort_median(a, 0, 17);
    
    for (int i = 0; i < 18; i++) {
        printf("%d ", a[i]);
    }
    
    printf("\nquick sort 실행횟수 : %d",quick);
    printf("\nquick sort (median) 실행횟수 : %d\n",quick_median);
    return 0;
}
