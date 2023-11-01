#include "binary_trees.h"

/**
 * binary_tree_sibling - a function that finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: NULL if node, parent or sibling is NULL else pointer to sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling, *p;
	int data;

	if (!node || !node->parent)
		return (NULL);

	data = node->n;
	p = node->parent;
	if (p->left && p->right)
	{
		sibling = (data == p->left->n) ? (p->right) : (p->left);
		return (sibling);
	}
	return (NULL);
}
