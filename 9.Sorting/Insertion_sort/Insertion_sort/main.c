#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


//시간복잡도
//최악 : O(n^2)

//책에 쓰여진 코드
void insertion_sort(int list[], int n){
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = list[i];
        for(j = i-1; j >= 0 && list[j] > key; j--)
            list[j+1] = list[j];    //레코드의 오른쪽 이동
        list[j+1] = key;
    }
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    
    int list[MAX_SIZE];
    for (int i = 0; i<MAX_SIZE; i++) {
        list[i] = rand()%MAX_SIZE;
    }
    
    insertion_sort(list, MAX_SIZE);
  
    
    print_array(list, MAX_SIZE);
    
    
    return 0;
}
