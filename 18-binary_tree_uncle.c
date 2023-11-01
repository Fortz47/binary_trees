#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: Null if node or has no uncle else pointer to uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent->parent)
		return (NULL);

	parent = node->parent;
	uncle = 
}
