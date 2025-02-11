#include "rb.h"

/* Constructor */
map_t map_new(size_t s1, size_t s2, int (*cmp)(const void *, const void *))
{
    map_t tree = (map_internal_t *) malloc(sizeof(map_internal_t));
    internal_map_new(tree);
    return tree;
}

/* Add function */
bool map_insert(map_t obj, void *key, void *val)
{
    map_node *node = (map_node *) malloc(sizeof(map_node));
    node->key = key;
    node->val = val;
    internal_map_insert(obj, node);
    return true;
}

/* Get functions */
void map_find(map_t obj, map_iter_t *it, void *key)
{
    map_node *tmp_node = (map_node *) malloc(sizeof(map_node));
    tmp_node->key = key;
    it->node = internal_map_search(obj, tmp_node);
    free(tmp_node);
}

bool map_empty(map_t obj)
{
    return (NULL == obj->root);
}

/* Iteration */
bool map_at_end(map_t UNUSED, map_iter_t *it)
{
    return (NULL == it->node);
}

/* Remove functions */
void map_erase(map_t obj, map_iter_t *it)
{
    if (NULL == it->node)
        return;
    internal_map_remove(obj, it->node);
}

/* Empty map */
void map_clear(map_t obj)
{
    internal_map_destroy(obj, NULL, NULL);
}

/* Destructor */
void map_delete(map_t obj)
{
    map_clear(obj);
    free(obj);
}

