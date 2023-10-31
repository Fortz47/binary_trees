#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 *                           (parent node)
 * @parent: A pointer to the node to insert the left-child
 * @value: The value to store in the new node
 *
 * Return: A pointer to the created node
 *         NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;
	int old_child_value;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->right = NULL;

	/* Check if the parent already has a left-child */
	if (parent->left)
	{
		old_child_value = parent->left->n;
		/* Create another new node as the left-child of `new` */
		new->left = binary_tree_node(new, old_child_value);
		/* Free the parent left-child for reallocation */
		free(parent->left);
	}
	else
		new->left = NULL;

	parent->left = new;

	return (new);
}
