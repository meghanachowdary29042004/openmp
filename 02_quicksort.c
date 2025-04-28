#include <stdio.h>
#include <omp.h>

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        
        arr[high] = temp;
        int pi = i+1;

        #pragma omp parallel sections
        {
            #pragma omp section
            quickSort(arr, low, pi - 1);
            #pragma omp section
            quickSort(arr, pi + 1, high);
        }
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;
    
    quickSort(arr, 0, n-1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
