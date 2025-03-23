#include "node.h"
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    node_t *left_node;
    node_t *right_node;
};

node_t *create_node(int value)
{
    node_t *new_node = malloc(sizeof(node_t));

    new_node->value = value;
    new_node->left_node = NULL;
    new_node->right_node = NULL;

    return new_node;
}

int node_get_value(node_t *self)
{
    return self->value;
}

void node_set_value(int value, node_t *self)
{
    self->value = value;
}

node_t *node_get_right_node(node_t *self)
{
    return self->right_node;
}

void node_set_right_node(node_t *right_node, node_t *self)
{
    self->right_node = right_node;
}

node_t *node_get_left_node(node_t *self)
{
    return self->left_node;
}

void node_set_left_node(node_t *left_node, node_t *self)
{
    self->left_node = left_node;
}