#include "binary_trees.h"

/**
 * binary_tree_rotate_left - a function that performs a
 * left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root = NULL;

	if (tree != NULL)
	{
		new_root = tree->right;
		tree->right = new_root->left;
		new_root->left = tree;
	}
	return (new_root);
}