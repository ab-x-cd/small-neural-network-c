#ifndef NETWORK_H
#define NETWORK_H

#include <stddef.h>

// Structure for a layer
typedef struct {
    size_t input_size;
    size_t output_size;
    float* weights; // weights: output_size x input_size
    float* biases;  // biases: output_size
    float* outputs; // outputs: output_size
} Layer;

// Structure for a neural network
typedef struct {
    size_t num_layers;
    Layer* layers;
    size_t neuron_count;
} NeuralNetwork;

// Functions
NeuralNetwork* create_network(size_t* layer_sizes, size_t num_layers);
void free_network(NeuralNetwork* net);
void forward(NeuralNetwork* net, float* input);

#endif // NETWORK_H
