#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0, nodes = 0, expected_nodes = 1;

	if (tree == NULL)
		return (0);

	/* Calculate height and expected nodes for a perfect tree */
	while (tree->left)
	{
		height++;
		expected_nodes = (expected_nodes << 1) + 1;
		tree = tree->left;
	}

	/* Calculate the actual number of nodes */
	nodes = (1 << height) - 1;

	return (nodes == expected_nodes);
}
