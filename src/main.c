#include <stdio.h>
#include "memtrack.h"
#include "matrix.h"
#include "network.h"

int main() {
    printf("Neural Network Project by BliinD\n");

    // Example: XOR problem
    size_t layer_sizes[] = {2, 2, 1}; // 2 inputs, 2 hidden, 1 output
    NeuralNetwork* net = create_network(layer_sizes, 3);
    printf("Total neurons in network: %zu\n", net->neuron_count);
    printf("Memory usage after network allocation: %zu bytes\n", mt_get_usage());

    // Training data for XOR
    float* inputs[4];
    float* targets[4];
    float input_data[4][2] = {{0,0}, {0,1}, {1,0}, {1,1}};
    float target_data[4][1] = {{0}, {1}, {1}, {0}};

    for (int i = 0; i < 4; ++i) {
        inputs[i] = input_data[i];
        targets[i] = target_data[i];
    }

    // Train the network
    train(net, inputs, targets, 4, 1000, 0.1f);

    // Test the trained network
    printf("Testing trained network:\n");
    for (int i = 0; i < 4; ++i) {
        forward(net, inputs[i]);
        printf("Input: %.0f %.0f, Output: %.3f, Target: %.0f\n",
               inputs[i][0], inputs[i][1], net->layers[1].outputs[0], targets[i][0]);
    }

    free_network(net);
    printf("Memory usage after free: %zu bytes\n", mt_get_usage());

    return 0;
}