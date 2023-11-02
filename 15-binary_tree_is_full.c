#include "binary_trees.h"

/**
 * full_tree_recursive_helper - Check if a binary tree is full
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int full_tree_recursive_helper(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	/* Check if one subtree is NULL and the other is not */
	if ((tree->left == NULL && tree->right != NULL) ||
			(tree->left != NULL && tree->right == NULL))
		return (0);


	return (full_tree_recursive_helper(tree->left) &&
		full_tree_recursive_helper(tree->right));
}

/**
 * binary_tree_is_full - Check if a binary tree is full
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int value;

	if (tree == NULL)
		return (0);

	value = full_tree_recursive_helper(tree);

	return (value);
}

