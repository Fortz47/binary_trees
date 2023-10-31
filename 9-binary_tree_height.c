#include "binary_trees.h"


/**
 */
size_t count_nodes(const binary_tree_t *tree, int count)
{
	if (tree != NULL)
	{
		count++;
		count_nodes(tree->left, count);
		count_nodes(tree->right, count);
		return (count);
	}
}
/**
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t count;
	
	if (tree == NULL)
		return (0);

	count = count_nodes(tree, 0);
	return (count);
}
