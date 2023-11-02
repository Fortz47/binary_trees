#include "binary_trees.h"

void free_queue(path_t *queue);
binary_tree_t *dequeue(path_t **queue);
path_t *enqueue(path_t **queue, const binary_tree_t *tree);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * free_queue - frees allocated path_t
 * @queue: The queue structure to be freed
 */
void free_queue(path_t *queue)
{
	path_t *temp;

	while (queue)
	{
		temp = queue;
		queue = queue->next;
		free(temp);
	}
}

/**
 * dequeue - pops a node from the queue
 * @queue: A pointer to the queue exit pointer
 *
 * Return: The popped tree node
 */
binary_tree_t *dequeue(path_t **queue)
{
	binary_tree_t *node;
	path_t *temp;

	if (!queue && !*queue)
		return (NULL);

	temp = *queue;

	node = (*queue)->node;

	*queue = (*queue)->next;

	free(temp);
	return (node);
}

/**
 * enqueue - pushes a node to the queue
 * @queue: A pointer to the queue exit pointer
 * @tree: The tree node to be pushed
 *
 * Return: The pushed node.
 */
path_t *enqueue(path_t **queue, const binary_tree_t *tree)
{
	path_t *new, *que;

	if (queue == NULL || tree == NULL)
		return (NULL);

	new = malloc(sizeof(path_t));
	if (!new)
		return (NULL);

	new->node = (binary_tree_t *)tree;
	new->next = NULL;

	if (*queue == NULL)
	{
		/* Add to the empty queue */
		*queue = new;

		return (new);
	}

	que = *queue;
	while (que->next)
		que = que->next;

	que->next = new;

	return (new);
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 *                          level-order traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function that prints each node value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	path_t *queue;
	binary_tree_t *node;

	if (tree == NULL || func == NULL)
		return;

	queue = NULL;

	enqueue(&queue, tree);

	while (queue != NULL)
	{
		node = dequeue(&queue);
		func(node->n);

		if (node->left)
			enqueue(&queue, node->left);

		if (node->right)
			enqueue(&queue, node->right);
	}

	free_queue(queue);
}
