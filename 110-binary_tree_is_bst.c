#include "binary_trees.h"
#include <limits.h>

/**
 * bst_recursive_helper - checks if a binary tree is a
 * valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * @min: minimum allowed
 * @max: maximum allowed
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int bst_recursive_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (bst_recursive_helper(tree->left, min, tree->n) &&
			bst_recursive_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid
 * Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int value;

	if (tree == NULL)
		return (0);

	value = bst_recursive_helper(tree, INT_MIN, INT_MAX);
	return (value);
}
