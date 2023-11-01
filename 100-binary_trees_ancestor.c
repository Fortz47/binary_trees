#include "binary_trees.h"
#include <stdio.h>
/**
 * free_path - frees allocated path_t
 * @path: The path to be freed
 */
void free_path(path_t *path)
{
	path_t *temp;

	while (path)
	{
		temp = path;
		path = path->next;
		free(temp);
	}
}


/**
 * add_to_path - adds a traced node to the current path
 * @path: A pointer to the path pointer
 * @node: The node to be added
 *
 * Return: A pointer to the new node added
 */
path_t *add_to_path(path_t **path, const binary_tree_t *node)
{
	path_t *new;

	if (node == NULL || path == NULL)
		return (NULL);

	new = malloc(sizeof(path_t));
	if (!new)
		return (NULL);

	new->node = (binary_tree_t *)node;
	new->next = *path;
	*path = new;

	return (new);
}
/**
 * path_to_root - traces a given node back to the root node and
 *                save all the nodes along the path
 * @subtree: A node to be traced to its root node
 *
 * Return: A complete path of the given node to its root, or
 *         NULL if `subtree` is NULL
 */
path_t *path_to_root(const binary_tree_t *subtree)
{
	const binary_tree_t *node = subtree;

	path_t *path = NULL;

	if (node == NULL)
		return (NULL);

	while (node)
	{
		add_to_path(&path, node);
		node = node->parent;
	}

	return (path);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor node of the two given nodes
 *         NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *node_1, *node_2;
	binary_tree_t *LCA, *prev_node = NULL;
	path_t *path_1 = NULL, *p_1, *p_2;
	path_t *path_2 = NULL;

	if (first == NULL || second == NULL)
		return (NULL);

	node_1 = first;
	node_2 = second;

	path_1 = path_to_root(node_1);
	path_2 = path_to_root(node_2);

	p_1 = path_1;
	p_2 = path_2;
	while (p_1 && p_2)
	{
		if (p_1->node != p_2->node)
			break;
		prev_node = p_1->node;
		p_1 = p_1->next;
		p_2 = p_2->next;
	}

	/* Save the Lowest Common Ancestor of the given subtrees */
	LCA = prev_node;

	free_path(path_1);
	free_path(path_2);

	return (LCA);
}
