#include <stdlib.h>
#include "stack.h"

LayerStack* create_stack(int max_capacity) {
    LayerStack* s = (LayerStack*)malloc(sizeof(LayerStack));
    s->top = -1;
    s->max_capacity = max_capacity;
    s->execution_array = (GraphNode*)malloc(max_capacity * sizeof(GraphNode));
    return s;
}

void push_node(LayerStack* s, GraphNode node) {
    if (s->top < s->max_capacity - 1) {
        s->execution_array[++(s->top)] = node;
    }
}

GraphNode pop_node(LayerStack* s) {
    if (s->top >= 0) {
        return s->execution_array[(s->top)--];
    }
    GraphNode empty = {0.0, 0.0};
    return empty;
}

void free_stack(LayerStack* s) {
    free(s->execution_array);
    free(s);
}
