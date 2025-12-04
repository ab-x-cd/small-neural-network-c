#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

// Matrix structure
typedef struct {
    size_t rows;
    size_t cols;
    float* data;
} Matrix;

// Matrix operations
Matrix* create_matrix(size_t rows, size_t cols);
void free_matrix(Matrix* mat);
int matrix_multiply(const Matrix* a, const Matrix* b, Matrix* result);
int matrix_add(const Matrix* a, const Matrix* b, Matrix* result);
void matrix_print(const Matrix* mat);

#endif // MATRIX_H
