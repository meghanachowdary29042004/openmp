#include <stdio.h>
#include <omp.h>

int sumDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void computeSumDigits(int *arr, int *result, int n) {
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        result[i] = sumDigits(arr[i]);
    }
}

int main() {
    int arr[] = {123, 456, 789};
    int n = 3;
    int result[3];
    
    computeSumDigits(arr, result, n);

    printf("Sum of digits: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}
