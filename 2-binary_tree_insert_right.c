#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 *                           (parent node)
 * @parent: A pointer to the node to insert the right-child
 * @value: The value to store in the new node
 *
 * Return: A pointer to the created node
 *         NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *old_child;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;

	/* Check if the parent already has a right-child */
	if (parent->right)
	{
		old_child = parent->right;
		/* Make the `new` node the parent of the `old_child` */
		old_child->parent = new;
		/* Assign the expected right-child */
		new->right = old_child;
	}
	else
		new->right = NULL;

	parent->right = new;

	return (new);
}
