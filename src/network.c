#include "network.h"
#include <stdlib.h>
#include <string.h>

NeuralNetwork* create_network(size_t* layer_sizes, size_t num_layers) {
    NeuralNetwork* net = (NeuralNetwork*)malloc(sizeof(NeuralNetwork));
    net->num_layers = num_layers - 1;
    net->layers = (Layer*)malloc((num_layers - 1) * sizeof(Layer));
    net->neuron_count = 0;


    for (size_t i = 0; i < num_layers - 1; ++i) {
        Layer* layer = &net->layers[i];
        layer->input_size = layer_sizes[i];
        layer->output_size = layer_sizes[i + 1];
        layer->weights = (float*)malloc(layer->output_size * layer->input_size * sizeof(float));
        layer->biases = (float*)malloc(layer->output_size * sizeof(float));
        layer->outputs = (float*)malloc(layer->output_size * sizeof(float));
        // Initialize weights and biases to small random values

        for (size_t j = 0; j < layer->output_size * layer->input_size; ++j)
            layer->weights[j] = ((float)rand() / RAND_MAX - 0.5f) * 0.1f;
            
        for (size_t j = 0; j < layer->output_size; ++j)
            layer->biases[j] = 0.0f;

        net->neuron_count += layer->output_size;
    }
    return net;
}

void free_network(NeuralNetwork* net) {
    for (size_t i = 0; i < net->num_layers; ++i) {
        Layer* layer = &net->layers[i];
        free(layer->weights);
        free(layer->biases);
        free(layer->outputs);
    }
    free(net->layers);
    free(net);
}

void forward(NeuralNetwork* net, float* input) {
    float* current_input = input;
    for (size_t l = 0; l < net->num_layers; ++l) {
        Layer* layer = &net->layers[l];
        for (size_t i = 0; i < layer->output_size; ++i) {
            float sum = layer->biases[i];
            for (size_t j = 0; j < layer->input_size; ++j) {
                sum += layer->weights[i * layer->input_size + j] * current_input[j];
            }
            // Simple activation (ReLU)
            layer->outputs[i] = sum > 0 ? sum : 0;
        }
        current_input = layer->outputs;
    }
}
