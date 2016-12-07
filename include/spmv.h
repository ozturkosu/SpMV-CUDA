#ifndef SPMV_H
#define SPMV_H

typedef struct
{
        int M, N, NNZ;
        float* A;
        int* IA;
        int* JA;
} SpMatrix;
/* Sparse Matrix Struct - CSR Format
 *      M - number of rows
 *      N - number of columns
 *      NNZ - number of nonzero elements
 *      A - pointer to float array containing nonzero elements (length NNZ)
 *      IA - pointer to row pointer array (length M+1)
 *      JA - pointer to column index array (length NNZ)
 */

void printArray(const float* arr, const int l);
/* Used to print A array from CSR formatted sparse matrix
 */

void printArray(const int* arr, const int l);
/* Used to print IA & JA array from CSR formatted sparse matrix
 */

void cpuSpMV(float* y, const SpMatrix A, const float* x);
/* For testing and correctness purposes.
 * CPU implementation of matrix-vector multiplication for sparse
*/

__global__
void spmvSimple(float * y, const float *A, const int *IA, const int *JA, const float *x);
/* Sparse matrix-vector multiplication for GPU
 * One thread computes one element of output vector
 *      y - output vector (M x 1)
 *      A - sparse matrix (M x N)
 *      x - input vector  (N x 1)
 */



bool areEqual(const float* a, const float* b);
/* Tests whether or not two vectors are equal. Returns 0 if they
 * are not equal and returns 1 if they are
 *      a, b - input vectors
 */

bool areEqual(const SpMatrix A, const SpMatrix B);
/* Tests whether a sparse matrix is equivalent to a regular matrix (for correctness
 purposes
        A, B - sparse matrices
*/

void printSpMatrix(const float* A, const int* IA, const int* JA, const int M, const int N);
void printSpMatrix(const SpMatrix S);
/* Takes in a sparse matrix in CSR format and prints the entire matrix using printf
 * WARNING: DO NOT USE THIS FUNCTION FOR LARGE MATRICES
 *      S - input sparse matrix
 */

// DOESN'T WORK YET...
void generateSquareSpMatrix(float* A, int* IA, int* JA, int* NNZ, const int N, const double p_diag, const double p_nondiag);
SpMatrix generateSquareSpMatrix(const int N, const double p_diag, const double p_nondiag);
/* Takes in a MxN size and two probabilities and generates one realization of a sparse matrix
 *      N - number of row (and columns)
 *      p_diag - probability of non-zero element on main diagonal
 *      p_nondiag - probability of non-zero element not on main diagonal
 */

void fillDenseVector(float* v, const int N);
/* Takes in a pointer, v, to a 1-D vector and a length N and fills it with random values
 * v - input vector pointer
 * N - input vector length
 */

#endif
