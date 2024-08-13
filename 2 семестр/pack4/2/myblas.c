void cblas_dgemm(int Order, int TransA, int TransB, int m, int n, int k, double alpha, double *A, int lda, double *B, int ldb, double beta, double *C, int ldc){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            C[i * n + j] *= beta;
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            double res = 0;
            for (int l = 0; l < k; l++){
                res += A[i * k + l] * B[l * n + j];
            }
            res *= alpha;
            C[i * n + j] += res;
        }
    }
}