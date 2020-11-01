//
//  main.c
//  Merge_sort
//
//  Created by APPLE on 08/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//


//책의 코드가 더 나은 듯

#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 10


//programiz에서 가져온 merge 코드
// Merge two subarrays L and M into arr
void merge_programiz(int list[], int left, int mid, int right) {
    
    // Create L ← A[left..mid] and M ← A[mid+1..right]
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], M[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = list[left + i];
    for (int j = 0; j < n2; j++)
        M[j] = list[mid + 1 + j];
    
    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = left;
    
    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            list[k] = L[i];
            i++;
        } else {
            list[k] = M[j];
            j++;
        }
        k++;
    }
    
    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        list[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        list[k] = M[j];
        j++;
        k++;
    }
}



//책의 코드 - 위의 코드보다 더 효율적인것 같음
void merge(int list[], int left, int mid, int right)
{
    int sorted[MAX_SIZE];
    int i = left , j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if(list[i] <= list[j])
            sorted[k++] = list[i++];

        else
            sorted[k++] = list[j++];

    }

    //남아있는 항목들 복사
    if(i <= mid)
        while(i <= mid)
            sorted[k++] = list[i++];
    else
        while (j <= right)
            sorted[k++] = list[j++];
        
    

    //배열 sorted[]의 리스트를 배열 list[]로 재복사
    for(int n = left; n <= right; n++)
        list[n] = sorted[n];

}


void merge_sort(int list[], int left, int right)
{
    if(left < right){
        int mid = (left + right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
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
    
    int list[MAX_SIZE] = {5 ,4, 2, 9, 8, 1, 3, 7, 6, 10};
//    for (int i = 0; i<MAX_SIZE; i++) {
//        list[i] = rand()%MAX_SIZE;
//    }
    
    merge_sort(list, 0, MAX_SIZE-1);
    
    print_array(list, MAX_SIZE);
    
    
    return 0;
}
