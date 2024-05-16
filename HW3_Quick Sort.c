#include <stdio.h>
#include <stdlib.h>

// 交換
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 利用pivot將陣列進行分割
int divide(int arr[], int start, int end) { 	 
    int pivot = arr[end]; // pivot為最後一個元素 
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[end]); // 將pivot位於左右兩個區段的中間 
    return (i + 1);
}

void quick_sort(int arr[], int start, int end) {
    if (start < end) {
        int pivot_index = divide(arr, start, end);
        // 遞迴排列左右陣列 
        quick_sort(arr, start, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, end);
    }
}

int main() {
    int arr[] = {33, 67, 8, 13, 54, 119, 3, 84, 25, 41};
    int n = sizeof(arr) / sizeof(arr[0]); //利用字節數得知元素數量 
    quick_sort(arr, 0, n - 1);
    printf("Quick Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
