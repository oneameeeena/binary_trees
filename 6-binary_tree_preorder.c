#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree using preorder traversal
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to apply to each node's value
 *
 * Performs a preorder traversal on the binary tree starting from the
 * given root node. It applies the given function to each node's value.
 *
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to apply to each node's value
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
