#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *new, *parent = NULL;

	if (tree == NULL)
		return (NULL);

	current = *tree;
	while (current)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}

	/* Create the new node */
	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	/* Decide where to attach the child to */
	if (parent == NULL)
		*tree = new;
	else if (value < parent->n)
		parent->left = new;
	else if (value > parent->n)
		parent->right = new;
	else
	{
		free(new);
		return (NULL);
	}
	return (new);
}
