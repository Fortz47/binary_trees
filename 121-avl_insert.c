#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: A double pointer to the root node of the AVL tree
 *        for inserting the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 *         NULL if `tree` is NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL || *tree == NULL)
		return (NULL);

	(void)value;

	return (NULL);
}
