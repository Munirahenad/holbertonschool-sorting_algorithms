#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes (left then right)
 * @list: Double pointer to the head of the list
 * @left: Left node
 * @right: Right node (must be left->next)
 */
static void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;

	right->next = left;
	left->prev = right;
}

/**
 * forward_pass - Performs forward pass of cocktail sort
 * @list: Double pointer to head of list
 * @end: Pointer to end marker (last node reached)
 *
 * Return: 1 if swapped happened, 0 otherwise
 */
static int forward_pass(listint_t **list, listint_t **end)
{
	listint_t *curr = *list;
	int swapped = 0;

	while (curr->next)
	{
		if (curr->n > curr->next->n)
		{
			swap_nodes(list, curr, curr->next);
			print_list(*list);
			swapped = 1;
		}
		else
			curr = curr->next;
	}
	*end = curr;
	return (swapped);
}

/**
 * backward_pass - Performs backward pass of cocktail sort
 * @list: Double pointer to head of list
 * @end: End marker from forward pass
 *
 * Return: 1 if swapped happened, 0 otherwise
 */
static int backward_pass(listint_t **list, listint_t *end)
{
	listint_t *curr = end;
	int swapped = 0;

	while (curr->prev)
	{
		if (curr->n < curr->prev->n)
		{
			swap_nodes(list, curr->prev, curr);
			print_list(*list);
			swapped = 1;
		}
		else
			curr = curr->prev;
	}
	return (swapped);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail shaker sort
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *end;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		swapped = forward_pass(list, &end);
		if (!swapped)
			break;
		swapped = backward_pass(list, end);
	} while (swapped);
}
