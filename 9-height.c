#include "binary_trees.h"
#include <stdio.h>

/**
 * _log2 - computes base 2 log of a number
 *
 * Return: log2 0f number
 */
double _log2(double x)
{
	return (log(x) / log(2));
}

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
 * binary_tree_height - calculates the height of a binary tree
 * @tree: pointer to the root node of the binary tree
 *
 * Return: height of the binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t count = 0;
	double height;
	
	if (tree == NULL)
		return (0);

	count_nodes(tree, &count);
	/* h = log2(n + 1) - 1 WHERE h is height and n is number of nodes*/
	height = _log2((double)count + 1) - 1;
	return ((size_t)height);
}
