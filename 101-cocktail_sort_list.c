#include "sort.h"

/**
 * swap_ahead - Swaps node with its next node (forward swap)
 * @list: Double pointer to head of list
 * @node: Pointer to node to move forward
 */
static void swap_ahead(listint_t **list, listint_t **node)
{
	listint_t *curr = *node;
	listint_t *next = curr->next;

	curr->next = next->next;
	if (next->next)
		next->next->prev = curr;

	next->prev = curr->prev;
	next->next = curr;

	if (curr->prev)
		curr->prev->next = next;
	else
		*list = next;

	curr->prev = next;
	*node = next;
}

/**
 * swap_behind - Swaps node with its prev node (backward swap)
 * @list: Double pointer to head of list
 * @node: Pointer to node to move backward
 */
static void swap_behind(listint_t **list, listint_t **node)
{
	listint_t *curr = *node;
	listint_t *prev = curr->prev;

	prev->next = curr->next;
	if (curr->next)
		curr->next->prev = prev;

	curr->prev = prev->prev;
	curr->next = prev;

	if (prev->prev)
		prev->prev->next = curr;
	else
		*list = curr;

	prev->prev = curr;
	*node = curr;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail shaker sort
 * @list: Double pointer to head of list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		curr = *list;

		/* Forward pass */
		while (curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_ahead(list, &curr);
				print_list(*list);
				swapped = 1;
			}
			else
				curr = curr->next;
		}

		if (!swapped)
			break;

		swapped = 0;

		/* Backward pass */
		while (curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_behind(list, &curr);
				print_list(*list);
				swapped = 1;
			}
			else
				curr = curr->prev;
		}
	}
}
