#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 3

void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
                if (j == n-1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int mat[N][N], int n) {
    if (n == 1) return mat[0][0];

    int temp[N][N];
    int D = 0;

    #pragma omp parallel for reduction(+:D)
    for (int f = 0; f < n; f++) {
        getCofactor(mat, temp, 0, f, n);
        int sign = (f%2==0) ? 1 : -1;
        D += sign * mat[0][f] * determinant(temp, n-1);
    }
    return D;
}

int main() {
    int mat[N][N] = {{1, 2, 3}, {0, 4, 5}, {1, 0, 6}};
    
    int det = determinant(mat, N);
    printf("Determinant: %d\n", det);
}
