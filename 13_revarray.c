#include <stdio.h>
#include <omp.h>

void reverseArray(int *arr, int n) {
    #pragma omp parallel for
    for (int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    
    reverseArray(arr, n);

    printf("Reversed Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
