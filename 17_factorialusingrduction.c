#include <stdio.h>
#include <omp.h>

long long computeFactorial(int n) {
    long long fact = 1;
    #pragma omp parallel for reduction(*:fact)
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n = 5;
    long long result = computeFactorial(n);
    printf("Factorial of %d is %lld\n", n, result);
}
