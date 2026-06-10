#include <stdio.h>
#include "stack.h"

int main() {
    printf("🗦 Initializing Backprop-Stack-C Derivative Chain Layer...\n\n");

    // Instantiating memory footprint allocation models
    LayerStack* backprop_pipeline = create_stack(5);

    // Creating mock neuron node configurations
    GraphNode input_weight_node = {0.45, 0.0};
    GraphNode hidden_weight_node = {0.72, 0.0};
    GraphNode output_loss_node = {1.00, 0.38}; // Initiating ground cost error trigger

    // Push execution nodes forward onto the stack layer
    push_node(backprop_pipeline, input_weight_node);
    push_node(backprop_pipeline, hidden_weight_node);
    push_node(backprop_pipeline, output_loss_node);

    printf("📉 Pulling nodes backwards off the stack to calculate gradients via the chain rule:\n");
    
    // Process chain-rule corrections iteratively (Backpropagation tracking mechanism)
    GraphNode layer_n = pop_node(backprop_pipeline);
    double accumulated_gradient = layer_n.gradient_delta;

    GraphNode layer_n_minus_1 = pop_node(backprop_pipeline);
    layer_n_minus_1.gradient_delta = accumulated_gradient * layer_n_minus_1.node_weight;
    
    printf("   • Hidden Weight Target Node Gradient Delta -> %.4f\n", layer_n_minus_1.gradient_delta);

    GraphNode layer_n_minus_2 = pop_node(backprop_pipeline);
    layer_n_minus_2.gradient_delta = layer_n_minus_1.gradient_delta * layer_n_minus_2.node_weight;
    
    printf("   • Input Weight Target Node Gradient Delta  -> %.4f\n", layer_n_minus_2.gradient_delta);

    free_stack(backprop_pipeline);
    return 0;
}
