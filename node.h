#ifndef NODE_H
#define NODE_H

typedef struct node node_t;

node_t *create_node(int value);

int node_get_value(node_t *self);
void node_set_value(int value, node_t *self);

node_t *node_get_right_node(node_t *self);
void node_set_right_node(node_t *right_node, node_t *self);

node_t *node_get_left_node(node_t *self);
void node_set_left_node(node_t *left_node, node_t *self);

#endif