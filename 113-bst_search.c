#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: A pointer to the root node of the BST to search
 * @value: The value to search in the tree
 *
 * Return: A pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *current;

	if (tree == NULL)
		return (NULL);

	current = tree;
	while (current)
	{
		if (current->n == value)
			return ((bst_t *)current);
		if (current->n > value)
			current = current->left;
		else if (value > current->n)
			current = current->right;
	}

	return (NULL);
}
