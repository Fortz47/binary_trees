#include "binary_trees.h"

/**
 * builds an AVL tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of element in the array
 *
 * Return: A pointer to the root node of the created AVL tree, or
 *         NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
}