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
        return reference_node;
    }

    else if (node_get_value(node) < node_get_value(reference_node))
    {
        node_set_left_node(insert(node, node_get_left_node(reference_node)),reference_node);
        return reference_node;
    }

    else
    {
        perror("[*] cannot insert, the element already exists [*]");
        return NULL;
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

node_t *delete(int value, node_t *node_reference)
{
    if (node_reference == NULL)
    {
        perror("cannot delete, this element isn't into this tree");
        return NULL;
    }

    if (value > node_get_value(node_reference))
    {
        node_set_right_node(delete(value, node_get_right_node(node_reference)), node_reference);
        return node_reference;
    }

    if (value < node_get_value(node_reference))
    {
        node_set_left_node(delete(value, node_get_left_node(node_reference)), node_reference);
        return node_reference;
    }

    if (node_get_value(node_reference) == value)
    {
        return NULL;
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

void avl_update(int old_value, int new_value, avl_t *self)
{
    /*
    sem fazer o free, ele vai pesquisar igual o delete, e vai reaproveitar o nodo,
    primeiro verifica se o new value existe na arvore, se não, aí ele vai fazer a substituição
    vai encontrar o old_value, se sim, aponta do pai dele para null se for na direita ou na esquerda
    pega esse old value, e modifica o valor dele para new value
    e por fim insere ele com o novo valor novamente na arvore
    */
}

void avl_delete(int value, avl_t *self)
{
    self->root = delete(value, self->root);
}

node_t *get_root(avl_t *self)
{
    return self->root;
}