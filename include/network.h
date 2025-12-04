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
    float* weight_gradients; // gradients for weights
    float* bias_gradients;   // gradients for biases
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
void backward(NeuralNetwork* net, float* input, float* target, float learning_rate);
void train(NeuralNetwork* net, float** inputs, float** targets, size_t num_examples, size_t epochs, float learning_rate);

#endif // NETWORK_H
