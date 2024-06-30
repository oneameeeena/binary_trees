#include "binary_trees.h"

int binary_tree_is_bst(const binary_tree_t *tree);
int is_bst_helper(const binary_tree_t *tree, int low, int high);
/**
 * binary_tree_is_bst - Checks if a binary tree is a Binary Search Tree (BST)
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a BST, 0 otherwise or if tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_helper - Checks if a binary tree is a Binary Search Tree (BST)
 * @tree: Pointer to the root node of the tree
 * @low: The minimum value a node can take
 * @high: The maximum value a node can take
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		return (is_bst_helper(tree->left, low, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, high));
	}

	return (1);
}
