#ifndef SORT_H
#define SORT_H


#include <string.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


int _intcmp(int a, int b);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void _swapints(int *array, size_t i, size_t j);
void print_array(const int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *left, listint_t *right);

#endif /* SORT_H */

