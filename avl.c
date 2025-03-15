#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// PRIVATE //

struct avl 
{
    node_t *root;
};

int calculate_balance_value(node_t *node_reference)
{
    if (node_reference != NULL)
    {
        return node_get_height(node_get_left_node(node_reference)) - node_get_height(node_get_right_node(node_reference));
    }
    else
    {
        return 0;
    }
}

node_t *rotate_left(node_t *node_reference);
node_t *rotate_right(node_t *node_reference);
node_t *rotate_left_right(node_t *node_reference);
node_t *rotate_right_left(node_t *node_reference);

node_t *balance(node_t *node_reference)
{
    int balance_value = calculate_balance_value(node_reference);

    if (balance_value < -1 && calculate_balance_value(node_get_right_node(node_reference)) <= 0)
    {
        node_reference = rotate_left(node_reference);
    }

    else if (balance_value > 1 && calculate_balance_value(node_get_left_node(node_reference)) >= 0)
    {
        node_reference = rotate_right(node_reference);
    }

    else if (balance_value > 1 && calculate_balance_value(node_get_right_node(node_reference)) < 0)
    {
        node_reference = rotate_left_right(node_reference);
    }

    else if (balance_value < -1 && calculate_balance_value(node_get_right_node(node_reference)) > 0)
    {
        node_reference = rotate_right_left(node_reference);
    }

    return node_reference;
}

int calculate_height(node_t *self)
{
    int left_height = node_get_height(node_get_left_node(self));
    int right_height = node_get_height(node_get_right_node(self));
    
    int greater_height = left_height > right_height ? left_height : right_height;
    greater_height += 1;
}

void set_root(node_t *root, avl_t *self) 
{
    self->root = root;
}

node_t *get_root(avl_t *self)
{
    return self->root;
}

node_t *insert(node_t *node, node_t* node_reference)
{
    if (node_reference == NULL)
    {
        return node;
    }

    if (node_get_value(node) < node_get_value(node_reference))
    {
        node_set_left_node(insert(node, node_get_left_node(node_reference)), node_reference);
    }
    else if (node_get_value(node) > node_get_value(node_reference))
    {
        node_set_right_node(insert(node, node_get_right_node(node_reference)), node_reference);
    }
    else
    {
        perror("[*] cannot insert, this element already exists [*]");
    }

    node_set_height(calculate_height(node_reference), node_reference);

    node_reference = balance(node_reference);

    return node_reference;
}

// PUBLIC //

avl_t *create_avl()
{
    avl_t *new_avl = malloc(sizeof(avl_t));

    new_avl->root = NULL;

    return new_avl;
}

void avl_insert(node_t *node, avl_t *self) 
{
    set_root(insert(node, get_root(self)), self);
}

node_t *avl_search(int value, avl_t *self)
{
    // NOT IMPLEMENTED YET
    return NULL;
}

void avl_update(int old_value, int new_value, avl_t *self)
{
    // NOT IMPLEMENTED YET
    return;
}

void avl_delete(int value, avl_t *self)
{
    // NOT IMPLEMENTED YET
    return;
}

