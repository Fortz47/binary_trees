#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: A pointer to the parent node of the node to be created
 * @value: The value to put in the new node
 *
 * Return: A pointer to the created new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
