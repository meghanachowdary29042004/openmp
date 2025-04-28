#include <stdio.h>
#include <omp.h>

int dotProduct(int *a, int *b, int n) {
    int product = 0;
    #pragma omp parallel for reduction(+:product)
    for (int i = 0; i < n; i++) {
        product += a[i] * b[i];
    }
    return product;
}

int main() {
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int n = 3;
    int result = dotProduct(a, b, n);
    printf("Dot Product: %d\n", result);
}
