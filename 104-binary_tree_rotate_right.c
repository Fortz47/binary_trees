#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a function that performs a
 * right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root = NULL;

	if (tree != NULL)
	{
		new_root = tree->left;
		tree->left = new_root->right;
		new_root->right = tree;
	}
	return (new_root);
}
