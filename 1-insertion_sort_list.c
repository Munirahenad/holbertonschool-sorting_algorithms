#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 *
 * Description: Sorts the list by swapping nodes and prints after each swap
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *node_to_insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		node_to_insert = current;
		current = current->next;

		while (node_to_insert->prev != NULL &&
		       node_to_insert->prev->n > node_to_insert->n)
		{
			sorted = node_to_insert->prev;

			if (node_to_insert->next != NULL)
				node_to_insert->next->prev = sorted;

			sorted->next = node_to_insert->next;
			node_to_insert->prev = sorted->prev;

			if (sorted->prev != NULL)
				sorted->prev->next = node_to_insert;
			else
				*list = node_to_insert;

			sorted->prev = node_to_insert;
			node_to_insert->next = sorted;

			print_list(*list);
		}
	}
}
