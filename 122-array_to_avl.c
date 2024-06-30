#include "binary_trees.h"

/**
 * array_to_avl - Converts an array of integers into an AVL tree
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * Return: Pointer to the root of the constructed AVL tree
 *         Returns NULL if the array is NULL or empty
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t index, jndex;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		for (jndex = 0; jndex < index; jndex++)
		{
			if (array[jndex] == array[index])
				break;
		}
		if (jndex == index)
		{
			if (avl_insert(&tree, array[index]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
