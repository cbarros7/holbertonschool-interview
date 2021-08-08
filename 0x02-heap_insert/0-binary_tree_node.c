#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - node of binary tree
 * @parent: ptr to head node of node to create
 * @value: value to put in node
 * Return: ptr to new node or NULL if fail
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new;

new = malloc(sizeof(binary_tree_t));
if (new == NULL)
return (NULL);

new->n = value;
new->parent = parent;
new->left = NULL;
new->right = NULL;

return (new);
}
