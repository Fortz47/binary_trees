#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, or 0 if `tree` is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height, left_path, right_path;

	if (tree == NULL)
		return (0);

	left_path = 1 + binary_tree_height(tree->left);
	right_path = 1 + binary_tree_height(tree->right);

	height = (left_path > right_path) ? left_path : right_path;

	return (height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * Description: Balance Factor = Height of left subtrees
 *                               - Height of right subtries
 * @tree: A pointer to the root node of the tree to measure its balance factor
 *
 * Return: The balance factor of a tree, 0r, 0 if `tree` is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int factor, height_left, height_right;

	if (tree == NULL)
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	factor = height_left - height_right;

	return (factor);
}
