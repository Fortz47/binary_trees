#include "binary_trees.h"

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 *         0 if `tree` is NULL
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if ((tree->left != NULL) && (tree->left->n > tree->n))
		return (0);

	if ((tree->right != NULL) && (tree->right->n > tree->n))
		return (0);

	return (binary_tree_is_heap(tree->left) &&
		binary_tree_is_heap(tree->right));
}
