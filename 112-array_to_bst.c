#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of element in the array
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	root = NULL;
	i = 0;
	while (i < size)
	{
		bst_insert(&root, array[i]);
		i++;
	}

	return (root);
}
