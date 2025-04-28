#include <stdio.h>
#include <omp.h>

#define N 3

int main() {
    int mat[N][N] = {{1,2,3},{4,5,6},{7,8,9}};
    int rowSum[N] = {0};
    int colSum[N] = {0};

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            #pragma omp atomic
            rowSum[i] += mat[i][j];
            #pragma omp atomic
            colSum[j] += mat[i][j];
        }
    }

    printf("Row sums: ");
    for (int i = 0; i < N; i++) printf("%d ", rowSum[i]);
    printf("\nColumn sums: ");
    for (int j = 0; j < N; j++) printf("%d ", colSum[j]);
    printf("\n");
}
