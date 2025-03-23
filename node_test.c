#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "assert.h"

int main(void)
{
    node_t *n1 = create_node(1);
    node_t *n2 = create_node(2);
    node_t *n3 = create_node(3);

    assert(node_get_left_node(n2) == NULL);
    assert(node_get_right_node(n2) == NULL);

    node_set_left_node(n1, n2);
    node_set_right_node(n3, n2);

    assert(node_get_left_node(n2) == n1);
    assert(node_get_right_node(n2) == n3);

    assert(node_get_value(node_get_left_node(n2)) == 1);
    assert(node_get_value(node_get_right_node(n2)) == 3);
    
    free(n1);
    free(n2);
    free(n3);
}