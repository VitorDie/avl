#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct avl 
{
    node_t *root;
};

avl_t *create_avl()
{
    avl_t *new_avl = malloc(sizeof(avl_t));

    new_avl->root = NULL;

    return new_avl;
}

node_t *insert(node_t *node, node_t *reference_node)
{
    if (reference_node == NULL)
    {
        return node;
    }

    if (node_get_value(node) > node_get_value(reference_node))
    {
        node_set_right_node(insert(node, node_get_right_node(reference_node)), reference_node);
    }

    else if (node_get_value(node) < node_get_value(reference_node))
    {
        node_set_left_node(insert(node, node_get_left_node(reference_node)),reference_node);
    }

    else
    {
        perror("[*] cannot insert, the element already exists [*]");
    }
}

node_t *search(int value, node_t *node_reference)
{
    if (node_reference == NULL)
    {
        perror("this element isn't into this tree");
        return NULL;
    }

    if (node_get_value(node_reference) == value)
    {
        return node_reference;
    }

    if (value > node_get_value(node_reference))
    {
        return search(value, node_get_right_node(node_reference));
    }
    
    if (value < node_get_value(node_reference))
    {
        return search(value, node_get_left_node(node_reference));
    }
}

void avl_insert(node_t *node, avl_t *self)
{
    self->root = insert(node, self->root);
}

node_t *avl_search(int value, avl_t *self)
{
    return search(value, self->root);
}

void avl_update(int old_value, int new_value, avl_t *self);
void avl_delete(int value, avl_t *self);

node_t *get_root(avl_t *self)
{
    return self->root;
}