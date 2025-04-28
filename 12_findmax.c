#include <stdio.h>
#include <omp.h>

int findMax(int *arr, int n) {
    int maxVal = arr[0];
    #pragma omp parallel for reduction(max:maxVal)
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    int arr[] = {5, 9, 1, 3, 7};
    int n = 5;
    int maxElement = findMax(arr, n);
    printf("Maximum element: %d\n", maxElement);
}
