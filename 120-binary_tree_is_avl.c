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

/**
 * binary_tree_height - Calculates the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl_helper - Helper function to check if a binary tree
 * is a valid AVL Tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl_helper(const binary_tree_t *tree)
{
	int left_height, right_height, height_diff;

	if (tree == NULL)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	height_diff = left_height > right_height ? left_height - right_height
		: right_height - left_height;

	if (height_diff > 1)
		return (0);

	return (binary_tree_is_avl_helper(tree->left) &&
			binary_tree_is_avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_avl_helper(tree) &&
			binary_tree_is_bst(tree));
}
