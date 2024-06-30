#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses a binary tree using inorder traversal
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to apply to each node's value
 *
 * Performs an inorder traversal on the binary tree starting from the
 * given root node. It applies the given function to each node's value.
 *
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to apply to each node's value
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
