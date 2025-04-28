#include <stdio.h>
#include <omp.h>

int sumNaturalNumbers(int n) {
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int n = 10;
    int result = sumNaturalNumbers(n);
    printf("Sum of first %d natural numbers: %d\n", n, result);
}
