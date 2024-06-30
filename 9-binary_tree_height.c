#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Calculates the height of a binary tree starting from the provided root node.
 * Returns the height of the tree. If the tree is NULL, it returns 0.
 *
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree, 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef = 0, rig = 0;

		lef = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		rig = tree->right ? 1 + binary_tree_height(tree->right) : 0;

		return ((lef > rig) ? lef : rig);
	}

	return (0);
}
