#ifndef STACK_H
#define STACK_H

typedef struct {
    double node_weight;
    double gradient_delta;
} GraphNode;

typedef struct {
    int top;
    int max_capacity;
    GraphNode* execution_array;
} LayerStack;

LayerStack* create_stack(int max_capacity);
void push_node(LayerStack* s, GraphNode node);
GraphNode pop_node(LayerStack* s);
void free_stack(LayerStack* s);

#endif
