//
//  main.c
//  Quick_sort
//
//  Created by APPLE on 09/07/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

//책의 코드와 외국사이트의 코드가 다르다
//아직 뭐가 더 효율적인지는 모르겠다


#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 1000
#define SWAP(a,b,tmp) (tmp = a , a = b , b = tmp)

int partition(int [], int, int);



//책에 있는 파티션코드 - 우리나라 개발자 대부분이 이 방식을 사용하는듯 하다
int partition(int list[], int left, int right)
{

    int pivot = left;
    
    int i = left + 1 , j = right , temp;
    
    while (i <= j) {
        while(list[i] < list[pivot])
            i++;
        while(list[j] > list[pivot])
            j--;
        if( i <= j){
            SWAP(list[i], list[j], temp);
            i++; j--;
        }
    }
    SWAP(list[pivot], list[j], temp);
    
    return j;
   
}
void quick_sort(int list[], int left, int right)
{
    if(left < right){
        int q = partition(list, left, right);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);
    }
}

//programiz에 있는 파티션 코드
//외국사이트의 코드가 다 이 구조이다(가장 오른쪽 요소를 피벗으로 둔다)
int partition_programiz(int list[], int left, int right)
{
    int pivot = list[right];
    int i = left - 1;
    int temp = 0;
    
    for (int j = left; j < right; j++) {
        if (list[j] <= pivot) {
            i++;
            SWAP(list[i], list[j], temp);
        }
    }
    
    SWAP(list[i+1], list[right], temp);
    return i + 1;
}


//가장 왼쪽의 요소를 피벗으로 두는 경우 (외국사이트들의 방식)
//이 partition 코드가 가장 좋은 것 같다 (가장 왼쪽 요소를 피벗으로 둠, 간결한 제어문)
int partition_leftmost(int list[], int left, int right)
{
    int pivot = list[left];
    int i = left + 1;       // i : pivot 보다 큰 배열 값의 인덱스(시작점)
    int temp = 0;
    
    for(int j = i; j <= right; j++){
        if(list[j] <= pivot){
            SWAP(list[i], list[j], temp);
            i++;
        }
    }
    
    SWAP(list[left], list[i-1], temp);
    return i - 1;
}


//이 부분 어느 곳에서 가져온 코드든 동일하다
void quick_sort_programiz(int list[], int left, int right)
{
    if(left < right){
        int q = partition_leftmost(list, left, right);
        quick_sort_programiz(list, left, q-1);
        quick_sort_programiz(list, q+1, right);
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
    
//    int list[MAX_SIZE] = {5 ,4, 2, 9, 8, 1, 3, 7, 6, 10};
    int list[MAX_SIZE];
        for (int i = 0; i<MAX_SIZE; i++) {
            list[i] = rand()%MAX_SIZE;
        }
//
    quick_sort_programiz(list, 0, MAX_SIZE-1);
    
    print_array(list, MAX_SIZE);
    
    
    //퀵정렬의 최악의 경우 : 이미 정렬된 배열을 정렬할 때 시간복잡도가 가장 큽니다. 자세히 말하면 정렬하려는 배열의 모든 요소 중 가장 작거나 가장 큰 요소가 연속적으로 피벗으로 지정이 된다면 결국은 퀵정렬이 시퀀셜 솔트 같이 피벗 그 자체만 정렬된 자리에 배치됩니다. 즉 , 퀵 솔트 함수를 배열의 요소 수 만큼 반복을 해야 정렬이 완료되므로 시간복잡도도 빅오 오브 n제곱이 됩니다.
    
    //퀵정렬의 최상의 경우 : 피벗이 배열의 요소들의 값 중 평균값, 즉 중간값으로 지정이 될 때 가장 빠른 시간복잡도를 가집니다. 퀵 정렬이 수행될때마다 정렬할 배열이 반으로 줄어드므로 T(n) = 2T(n/2) + O(1) 즉 시간복잡도는 O(nlogn)이 됩니다.
    
    return 0;
}
