#include <stdio.h>
#include <stdbool.h>
#include "../include/matrix.h"
#include "../include/memtrack.h"

bool check_matrix_equal(const Matrix* a, const Matrix* b) {
    if (a->rows != b->rows || a->cols != b->cols) return false;
    for (size_t i = 0; i < a->rows * a->cols; ++i) {
        if (a->data[i] != b->data[i]) return false;
    }
    return true;
}

int main() {
    printf("Matrix Tests\n");

    Matrix* a = create_matrix(2, 2);
    Matrix* b = create_matrix(2, 2);
    Matrix* result = create_matrix(2, 2);

    a->data[0] = 1; a->data[1] = 2;
    a->data[2] = 3; a->data[3] = 4;

    b->data[0] = 5; b->data[1] = 6;
    b->data[2] = 7; b->data[3] = 8;

    // Test matrix_add
    matrix_add(a, b, result);
    float expected_add[4] = {6, 8, 10, 12};
    Matrix* expected = create_matrix(2, 2);
    for (int i = 0; i < 4; ++i) expected->data[i] = expected_add[i];
    printf("Addition test: %s\n", check_matrix_equal(result, expected) ? "PASSED" : "FAILED");

    // Test matrix_multiply
    matrix_multiply(a, b, result);
    float expected_mul[4] = {19, 22, 43, 50};
    for (int i = 0; i < 4; ++i) expected->data[i] = expected_mul[i];
    printf("Multiplication test: %s\n", check_matrix_equal(result, expected) ? "PASSED" : "FAILED");

    free_matrix(a);
    free_matrix(b);
    free_matrix(result);
    free_matrix(expected);

    printf("Memory usage after free: %zu bytes\n", mt_get_usage());

    return 0;
}