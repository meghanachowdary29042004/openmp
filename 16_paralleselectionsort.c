#include <stdio.h>
#include <omp.h>

void parallelSelectionSort(int *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        #pragma omp parallel for
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                #pragma omp critical
                {
                    if (arr[j] < arr[min_idx]) min_idx = j;
                }
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
    
    parallelSelectionSort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
