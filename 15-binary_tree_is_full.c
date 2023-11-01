#include "binary_trees.h"
#include <stdio.h>


/**
 * count_nodes - recursive helper function
 * @tree: pointer to root node of binary tree
 * @count: count variable
 *
 * Return: number of nodes in the binary tree
 */
void count_nodes(const binary_tree_t *tree, size_t *count)
{
	if (tree != NULL)
	{
		*count += 1;
		count_nodes(tree->left, count);
		count_nodes(tree->right, count);
	}
}

/**
 * tree_height - calculates the height of a binary tree
 * @tree: pointer to the root node of the binary tree
 *
 * Return: height of the binary tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t height, left_path, right_path;

	if (tree == NULL)
		return (0);

	/* Check if both `left-child` and `right-child` are not NULL */
	left_path = tree->left ? 1 + tree_height(tree->left) : 0;
	right_path = tree->right ? 1 + tree_height(tree->right) : 0;

	height = (left_path > right_path) ? left_path : right_path;

	return (height);
}

/**
 * binary_tree_is_full - a function that checks if a binary tree is full
 * @tree: pointer to root node of binary tree
 *
 * Return: 0 if tree is NUll or not full else 1
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t count = 0, full_tree, i = 1, level;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	level = tree_height(tree) + 1;
	/* evaluates 2**level */
	while (level)
	{
		i *= 2;
		level--;
	}

	full_tree = i - 1;
	count_nodes(tree, &count);
	if (count != full_tree)
		return (0);
	return (1);
}
