#include "binary_trees.h"

/**
 * sorted_array_to_avl - function that converts a sorted array to
 * an AVL tree (i.e. a self-balancing binary search tree; the heights of
 * the two child subtrees of any node differ by at most one;
 * if at any time they differ by more than one, rebalancing is done
 * to restore this property)
 *
 * @array: pointer to the sorted array
 * @size: size of the array to convert to AVL tree
 * Return: pointer to the root node of the AVL tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array || !size)
		return (NULL);

	root = recurse(array, 0, size - 1, NULL);

	return (root);
}

/**
 * recurse - utility function that constructs an AVL tree, recursively
 *
 * @array: pointer to the sorted array
 * @start: start index in the array
 * @end: end index in the array
 * @parent: pointer to the parent node
 * Return: pointer to the root node of the AVL tree
 */

avl_t *recurse(int *array, int start, int end, avl_t *parent)
{
	avl_t *new_node;
	int mid;

	/* Exit the recusion */
	if (start > end)
		return (NULL);

	/* Grab the index of the middle point in the sorted array */
	mid = (start + end) / 2;
	/* Instantiate a new node */
	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);

	/* Assign the value at index mid in the array */
	new_node->n = array[mid];
	new_node->parent = parent;
	/* Recursion calls that build the branches */
	new_node->left = recurse(array, start, mid - 1, new_node);
	new_node->right = recurse(array, mid + 1, end, new_node);
	return (new_node);
}
