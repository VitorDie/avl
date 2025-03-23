#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "avl.h"
#include <assert.h>

int main(void)
{
    avl_t *new_avl = create_avl();

    node_t *n1 = create_node(1);
    node_t *n2 = create_node(2);
    node_t *n3 = create_node(3);

    avl_insert(n2, new_avl);
    avl_insert(n1, new_avl);
    avl_insert(n3, new_avl);

    assert(node_get_left_node(n2) == n1);
    assert(node_get_right_node(n2) == n3);

    assert(node_get_value(node_get_left_node(n2)) == 1);
    assert(node_get_value(node_get_right_node(n2)) == 3);

//    assert(get_root(new_avl) == n2);

    assert(avl_search(2, new_avl) == n2);
    assert(avl_search(0, new_avl) == NULL);

    assert(avl_search(1, new_avl) == n1);
    assert(avl_search(3, new_avl) == n3);
    assert(node_get_value(n3) == 3);

    avl_delete(5, new_avl);

    avl_delete(3, new_avl);

    //assert(node_get_right_node(n2) == n3);
    assert(node_get_right_node(n2) == NULL);
    assert(avl_search(3, new_avl) == NULL);

    free(new_avl);
    free(n1);
    free(n2);
    free(n3);
    return 0;
}