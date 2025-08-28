#include <stdio.h>
#include "memtrack.h"
#include "matrix.h"
#include "network.h"

int main() {
    printf("Neural Network Project\n");

    Matrix* mat = create_matrix(12, 12);
    printf("Memory usage after allocation: %zu bytes\n", mt_get_usage());

    free_matrix(mat);
    printf("Memory usage after free: %zu bytes\n", mt_get_usage());


    size_t layer_sizes[] = {3, 5, 2}; // Example: 3 input, 5 hidden, 2 output
    NeuralNetwork* net = create_network(layer_sizes, 3);
    printf("Total neurons in network: %zu\n", net->neuron_count);
    printf("Memory usage after network allocation: %zu bytes\n", mt_get_usage());

    free_network(net);
    printf("Memory usage after network free: %zu bytes\n", mt_get_usage());

    return 0;
}