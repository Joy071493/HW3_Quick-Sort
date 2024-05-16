#include <stdio.h>
#include <stdlib.h>

// �洫
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// �Q��pivot�N�}�C�i�����
int divide(int arr[], int start, int end) { 	 
    int pivot = arr[end]; // pivot���̫�@�Ӥ��� 
    int i = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[end]); // �Npivot��󥪥k��ӰϬq������ 
    return (i + 1);
}

void quick_sort(int arr[], int start, int end) {
    if (start < end) {
        int pivot_index = divide(arr, start, end);
        // ���j�ƦC���k�}�C 
        quick_sort(arr, start, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, end);
    }
}

int main() {
    int arr[] = {33, 67, 8, 13, 54, 119, 3, 84, 25, 41};
    int n = sizeof(arr) / sizeof(arr[0]); //�Q�Φr�`�Ʊo�������ƶq 
    quick_sort(arr, 0, n - 1);
    printf("Quick Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
