#include "binary_trees.h"

/**
 * array_to_heap - Creates a heap from an array of integers
 * @array: Pointer to the array of integers
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created heap
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int index;
	heap_t *root = NULL;

	for (index = 0; index < size; index++)
		heap_insert(&root, array[index]);

	return (root);
}
