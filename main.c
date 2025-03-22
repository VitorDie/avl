#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "avl.h"
#include "assert.h"

int main(void)
{
    node_t *n1 = create_node(1);
    node_t *n2 = create_node(2);
    node_t *n3 = create_node(3);

    avl_t *myavl = create_avl();

    avl_insert(n2, myavl);
    avl_insert(n1, myavl);
    avl_insert(n3, myavl);

    assert(n2 == avl_search(2, myavl));
    assert(n3 == avl_search(3, myavl));
    assert(n1 == avl_search(1, myavl));

    free(n1);
    free(n2);
    free(n3);

    free(myavl);
}