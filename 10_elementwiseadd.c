#include <stdio.h>
#include <omp.h>

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {5, 4, 3, 2, 1};
    int c[5];
    int n = 5;

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }

    printf("Resultant array: ");
    for (int i = 0; i < n; i++) printf("%d ", c[i]);
    printf("\n");
}
