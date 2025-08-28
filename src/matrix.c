#include "matrix.h"
#include "memtrack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Matrix* create_matrix(size_t rows, size_t cols) {
    Matrix* mat = (Matrix*)mt_malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (float*)mt_calloc(rows * cols, sizeof(float));
    return mat;
}

void free_matrix(Matrix* mat) {
    mt_free(mat->data);
    mt_free(mat);
}


void matrix_multiply(const Matrix* a, const Matrix* b, Matrix* result) {
    if (a->cols != b->rows || result->rows != a->rows || result->cols != b->cols) return;
    for (size_t i = 0; i < a->rows; ++i) {
        for (size_t j = 0; j < b->cols; ++j) {
            float sum = 0.0f;
            for (size_t k = 0; k < a->cols; ++k) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            result->data[i * result->cols + j] = sum;
        }
    }
}

void matrix_add(const Matrix* a, const Matrix* b, Matrix* result) {
    if (a->rows != b->rows || a->cols != b->cols || result->rows != a->rows || result->cols != a->cols) return;
    for (size_t i = 0; i < a->rows * a->cols; ++i) {
        result->data[i] = a->data[i] + b->data[i];
    }
}

void matrix_print(const Matrix* mat) {
    for (size_t i = 0; i < mat->rows; ++i) {
        for (size_t j = 0; j < mat->cols; ++j) {
            printf("%8.4f ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}
