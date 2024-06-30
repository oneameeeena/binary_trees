#include "binary_trees.h"

int binary_tree_is_heap(const binary_tree_t *tree);
int check_parent(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - Checks if a binary tree follows the heap structure
 * @tree: Pointer to the root of the binary tree
 *
 * Return: 1 if the tree meets the heap structure, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * check_parent - Checks if the parent node values are greater than
 * their children's values
 * @tree: Pointer to the root of the binary tree
 *
 * Return: 1 if the parent values are greater than or equal
 * to their children's values, 0 otherwise.
 */
int check_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is a complete binary tree
 * @tree: Pointer to the root of the binary tree
 *
 * Return: 1 if the tree is a complete binary tree, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t cnodes;

	if (tree == NULL)
		return (0);

	cnodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, cnodes));
}

/**
 * tree_is_complete - Checks if a binary tree
 * satisfies the complete tree property
 * @tree: Pointer to the root of the binary tree
 * @i: Current index of the node being checked
 * @cnodes: Total number of nodes in the tree
 *
 * Return: 1 if the tree satisfies the complete tree property, 0 otherwise.
 */
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (tree == NULL)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}


/**
 * binary_tree_size - Measures the total number of nodes in a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: Total count of nodes in the binary tree; 0 if the tree is empty.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
