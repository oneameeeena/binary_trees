#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree
 * @node: Pointer to the node whose uncle is to be found
 *
 * @node: Pointer to the node whose uncle is to be found
 * Return: Pointer to the uncle node, or NULL if node is NULL, has no parent,
 * or its parent has no parent (grandparent), or the uncle does not exist
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
