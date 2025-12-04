#include "network.h"
#include <stdlib.h>
#include <string.h>
#include <math.h> // for expf if needed, but using ReLU
#include <stdio.h>

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
        layer->weight_gradients = (float*)malloc(layer->output_size * layer->input_size * sizeof(float));
        layer->bias_gradients = (float*)malloc(layer->output_size * sizeof(float));
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
        free(layer->weight_gradients);
        free(layer->bias_gradients);
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

void backward(NeuralNetwork* net, float* input, float* target, float learning_rate) {
    // Compute output layer error
    Layer* output_layer = &net->layers[net->num_layers - 1];
    float* output_errors = (float*)malloc(output_layer->output_size * sizeof(float));
    for (size_t i = 0; i < output_layer->output_size; ++i) {
        float output = output_layer->outputs[i];
        // MSE derivative: (output - target) * d(ReLU)/d(output)
        float d_activation = (output > 0) ? 1.0f : 0.0f; // ReLU derivative
        output_errors[i] = (output - target[i]) * d_activation;
    }

    // Backpropagate errors
    float* current_errors = output_errors;
    for (int l = (int)net->num_layers - 1; l >= 0; --l) {
        Layer* layer = &net->layers[l];
        float* prev_errors = (l > 0) ? (float*)malloc(layer->input_size * sizeof(float)) : NULL;

        // Compute gradients
        for (size_t i = 0; i < layer->output_size; ++i) {
            layer->bias_gradients[i] = current_errors[i];
            for (size_t j = 0; j < layer->input_size; ++j) {
                float input_val = (l == 0) ? input[j] : net->layers[l-1].outputs[j];
                layer->weight_gradients[i * layer->input_size + j] = current_errors[i] * input_val;
            }
        }

        // Update weights and biases
        for (size_t i = 0; i < layer->output_size; ++i) {
            layer->biases[i] -= learning_rate * layer->bias_gradients[i];
            for (size_t j = 0; j < layer->input_size; ++j) {
                layer->weights[i * layer->input_size + j] -= learning_rate * layer->weight_gradients[i * layer->input_size + j];
            }
        }

        // Compute errors for previous layer
        if (l > 0) {
            for (size_t j = 0; j < layer->input_size; ++j) {
                prev_errors[j] = 0.0f;
                for (size_t i = 0; i < layer->output_size; ++i) {
                    prev_errors[j] += layer->weights[i * layer->input_size + j] * current_errors[i];
                }
                // Apply ReLU derivative
                float prev_output = net->layers[l-1].outputs[j];
                prev_errors[j] *= (prev_output > 0) ? 1.0f : 0.0f;
            }
        }

        free(current_errors);
        current_errors = prev_errors;
    }
}

void train(NeuralNetwork* net, float** inputs, float** targets, size_t num_examples, size_t epochs, float learning_rate) {
    for (size_t epoch = 0; epoch < epochs; ++epoch) {
        float total_loss = 0.0f;
        for (size_t ex = 0; ex < num_examples; ++ex) {
            forward(net, inputs[ex]);
            backward(net, inputs[ex], targets[ex], learning_rate);
            // Compute loss (MSE)
            Layer* output_layer = &net->layers[net->num_layers - 1];
            for (size_t i = 0; i < output_layer->output_size; ++i) {
                float diff = output_layer->outputs[i] - targets[ex][i];
                total_loss += diff * diff;
            }
        }
        total_loss /= num_examples;
        if (epoch % 100 == 0) {
            printf("Epoch %zu, Loss: %f\n", epoch, total_loss);
        }
    }
}
