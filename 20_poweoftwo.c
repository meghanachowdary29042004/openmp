#include <stdio.h>
#include <omp.h>

int isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n-1)) == 0);
}

void checkPowerOfTwo(int *arr, int n) {
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        if (isPowerOfTwo(arr[i])) {
            printf("Index %d (Thread %d): %d is power of 2\n", i, omp_get_thread_num(), arr[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 8, 16, 23};
    int n = 8;
    
    checkPowerOfTwo(arr, n);
}
