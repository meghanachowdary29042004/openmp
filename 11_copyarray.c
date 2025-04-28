#include <stdio.h>
#include <omp.h>

void copyArray(int *src, int *dest, int n) {
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int n = 5;
    int src[] = {1, 2, 3, 4, 5};
    int dest[5];
    
    copyArray(src, dest, n);

    printf("Copied Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dest[i]);
    }
    printf("\n");
}
