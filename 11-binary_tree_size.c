#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * Description: This measure the total number of nodes in the given tree
 *
 * @tree: A pointer to the root node of the tree to measure the size
 *
 * Return: The size of the given tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);

	return (size);
}
