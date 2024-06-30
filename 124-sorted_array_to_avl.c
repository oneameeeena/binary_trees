#include "binary_trees.h"

avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last);

/**
 * sorted_array_to_avl - Convert a sorted array into an AVL tree
 * @array: Pointer to the first element of the sorted array
 * @size: Size of the array
 *
 * Return: Pointer to the root of the AVL tree, or NULL if array is NULL or
 * size is 0
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}

/**
 * aux_sort - Constructs an AVL tree from a sorted array segment
 * @parent: Parent node of the current node being created
 * @array: Pointer to the sorted array
 * @begin: Starting index of the array segment
 * @last: Ending index of the array segment
 *
 * Return: Pointer to the root of the constructed AVL tree, or NULL if the
 * beginning index is greater than the ending index.
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, begin, mid - 1);
		root->right = aux_sort(root, array, mid + 1, last);
		return (root);
	}
	return (NULL);
}
