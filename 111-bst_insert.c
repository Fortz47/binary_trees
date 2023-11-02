#include "binary_trees.h"

/**
 * check_value - checks if a value already present in a binary search tree
 * @tree: A pointer to the tree to check
 * @value: The value to check its presence
 *
 * Return: 1 if present, or 0 otherwise
 */
int check_value(bst_t *tree, int value)
{

	if (tree == NULL)
		return (0);

	if (tree->n == value)
		return (1);

	if (check_value(tree->left, value))
		return (1);

	if (check_value(tree->right, value))
		return (1);

	return (0);
}

/**
 * get_next_parent - gets the parent for the new node from the tree
 * @tree: A pointer to the root node of the tree
 *
 * Return: The expected node to assign a child to
 */
bst_t *get_next_parent(bst_t *tree, int value)
{
	if (tree->left == NULL || tree->left == NULL)
		return (tree);

	if (value < tree->n)
		return (get_next_parent(tree->left, value));
	if (value > tree->n)
		return (get_next_parent(tree->right, value));
}

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *next_parent, *new;
	int present;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		new = binary_tree_node(*tree, value);
		if (new == NULL)
			return (NULL);

		*tree = new;
		return (new);
	}

	/* Check if the value already exist in the tree */
	present = check_value(*tree, value);
	if (present)
		return (NULL);

	/* Get the parent to attach the new child to */
	next_parent = get_next_parent(*tree, value);

	new = binary_tree_node(next_parent, value);
	if (!new)
		return (NULL);

	/* Decide where to attach the child to */
	if (value >= next_parent->n)
		next_parent->right = new;
	else if (value <= next_parent->n)
		next_parent->left = new;

	return (new);
}
