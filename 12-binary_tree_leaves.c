#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: A pointer to the root node of the tree to count the number of leaves
 *
 * Return: The number of leaves in the `tree`, or 0 if `tree` is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves, left, right;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);

	leaves = left + right;

	return (leaves);
}