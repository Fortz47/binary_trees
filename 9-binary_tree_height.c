#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * Description: This measures the length of the longest path
 *              from the root node to a leaf node
 *              (also known as "maximum depth")
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, or 0 if `tree` is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height, left_path, right_path;

	if (tree == NULL)
		return (0);

	/* Check if both `left-child` and `right-child` are not NULL */
	left_path = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_path = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	height = (left_path > right_path) ? left_path : right_path;

	return (height);
}
