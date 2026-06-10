#include <stdio.h>
#include "stack.h"

// Computes the backpropagation chain rule step across the network graph layers
void execute_backprop_chain(LayerStack* stack) {
    if (stack == NULL || stack->top < 0) {
        printf("⚠️ Error: Execution stack trace is empty.\n");
        return;
    }

    // Step 1: Pop the Output/Loss Node to get the initial error seed
    GraphNode current_node = pop_node(stack);
    double cumulative_gradient = current_node.gradient_delta;
    
    printf("🎯 Seed Gradient from Loss Function Node: %.4f\n", cumulative_gradient);
    printf("---------------------------------------------------\n");

    // Step 2: Iteratively pop hidden and input layers to propagate the gradient backwards
    int layer_index = stack->top;
    while (stack->top >= 0) {
        GraphNode previous_node = pop_node(stack);
        
        // Applying the Chain Rule: dL/dx = dL/dy * dy/dx
        // The gradient flowing back is multiplied by the weight of the node it is passing through
        double computed_grad = cumulative_gradient * previous_node.node_weight;
        
        printf("⛓️  Layer [%d] Backprop Phase:\n", layer_index);
        printf("   • Node Weight Attribute: %.4f\n", previous_node.node_weight);
        printf("   • Computed Derivative Chain Step (Gradient Delta): %.4f\n\n", computed_grad);
        
        // Update the running cumulative gradient for the next layer down the stack
        cumulative_gradient = computed_grad;
        layer_index--;
    }
}
