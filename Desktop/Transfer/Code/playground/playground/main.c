/*
 You should use the statndard input/output
 
 in order to receive a score properly.
 
 Do not use file input and output
 
 Please be very careful.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SWAP(a,b,tmp) (tmp = a, a = b, b = tmp)

int Answer;

int partition(int arr[], int left, int right){
    int temp = 0;
    int pivot = arr[left];
    int j = left + 1;
    for(int i = left + 1; i <= right; i++){
        if(arr[i] <= pivot){
            SWAP(arr[i],arr[j],temp);
            j++;
        }
        
    }
    SWAP(arr[left],arr[j-1],temp);
    return j-1;
}

void quicksort(int arr[],int left,int right){
    if(left < right){
        int middle = partition(arr,left,right);
        quicksort(arr, left, middle-1);
        quicksort(arr, middle+1, right);
    }
}

int main(void)
{
    int T, test_case;
    /*
     The freopen function below opens input.txt file in read only mode, and afterward,
     the program will read from input.txt file instead of standard(keyboard) input.
     To test your program, you may save input data in input.txt file,
     and use freopen function to read from the file when using scanf function.
     You may remove the comment symbols(//) in the below statement and use it.
     But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */
    // freopen("input.txt", "r", stdin);
    
    /*
     If you remove the statement below, your program's output may not be rocorded
     when your program is terminated after the time limit.
     For safety, please use setbuf(stdout, NULL); statement.
     */
   // setbuf(stdout, NULL);
    printf("T입력 : ");
    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++)
    {
        
        /////////////////////////////////////////////////////////////////////////////////////////////
        int N;      //정수의 개수
        printf("정수의 개수 : ");
        scanf("%d",&N);
        int a[N];
        for(int i = 0; i < N; i++)
            scanf("%d",&a[i]);
        
        quicksort(a,0,N-1);
        
        int count = 1;
        bool first = true;
        int sum = 0;
        
        for(int i = 0; i < N; i++){
            if(a[i] == a[i+1]){
                count++;
            }
            else if(a[i] != a[i+1]){
                
                if(count%2 == 1){
                    if(first){
                        sum = a[i];
                        first = false;
                    }
                    else
                        sum = sum ^ a[i];
                }
                count = 1;
            }
            
        }
        Answer = sum;
        
        
        /////////////////////////////////////////////////////////////////////////////////////////////
        
        // Print the answer to standard output(screen).
        
        printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
        
    }
    
    return 0;//Your program should return 0 on normal termination.
}
