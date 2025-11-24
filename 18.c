#include <stdio.h>
#include <stdlib.h>

#define BLOCK 64   // 可以依 CPU cache 大小調整 (32/64/128)

void matmul_block(double **A, double **B, double **C, int n) {
    for (int ii = 0; ii < n; ii += BLOCK)
        for (int jj = 0; jj < n; jj += BLOCK)
            for (int kk = 0; kk < n; kk += BLOCK)

                for (int i = ii; i < ii + BLOCK && i < n; i++)
                    for (int j = jj; j < jj + BLOCK && j < n; j++) {
                        double sum = C[i][j];
                        for (int k = kk; k < kk + BLOCK && k < n; k++)
                            sum += A[i][k] * B[k][j];
                        C[i][j] = sum;
                    }
}
