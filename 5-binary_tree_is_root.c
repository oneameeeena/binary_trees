#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a root in a binary tree
 * @node: Pointer to the node to be checked
 *
 * Determines whether the given node is a root node (has no parent) in
 * a binary tree.
 *
 * Return: 1 if the node is a root, 0 otherwise or if the node is NULL.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
