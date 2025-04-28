#include <stdio.h>
#include <omp.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int countPrimes(int *arr, int n) {
    int count = 0;
    #pragma omp parallel for reduction(+:count)
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {2, 3, 4, 5, 6, 7};
    int n = 6;
    int primeCount = countPrimes(arr, n);
    printf("Number of primes: %d\n", primeCount);
}
