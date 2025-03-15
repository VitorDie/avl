#include "node.h"
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int value;
    struct node *right_node;
    struct node *left_node;
    int height;
}; 

node_t *create_node(int value)
{
    node_t *new_node = malloc(sizeof(node_t));

    new_node->value = value;
    new_node->right_node = NULL;
    new_node->left_node = NULL;
    new_node->height = 0;

    return new_node;
}

void node_set_value(int value, node_t *self)
{
    self->value = value;
}

int node_get_value(node_t *self)
{
    return self->value;
}

void node_set_right_node(node_t *right_node, node_t *self)
{
    self->right_node = right_node;
}

node_t *node_get_right_node(node_t *self)
{
    return self->right_node;
}

void node_set_left_node(node_t *left_node, node_t *self)
{
    self->left_node = left_node;
}

node_t *node_get_left_node(node_t *self)
{
    return self->left_node;
}

void node_set_height(int height,node_t *self)
{
    self->height = height;
}

int node_get_height(node_t *self)
{
    if (self == NULL)
    {
        return -1;
    }

    return self->height;
}