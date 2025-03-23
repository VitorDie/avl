#ifndef AVL_H
#define AVL_H

#include "node.h"

typedef struct avl avl_t;

avl_t *create_avl();

void avl_insert(node_t *node, avl_t *self);
node_t *avl_search(int value, avl_t *self);
void avl_update(int old_value, int new_value, avl_t *self);
void avl_delete(int value, avl_t *self);

#endif