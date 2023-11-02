#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: A pointer to the root node of the tree where you will remove a node
 * @value: The value to be removed from the tree
 *
 * Return: A pointer to the new root node of the tree after the desired value
 *         has been removed.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	(void)value;
}
