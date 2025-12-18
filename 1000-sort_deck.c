#include <stdlib.h>
#include <string.h>
#include "deck.h"

#define DECK_SIZE 52

/**
 * card_value_rank - Convert card value string to rank (0..12)
 * @value: Card value string
 *
 * Return: rank where Ace=0 ... King=12
 */
static int card_value_rank(const char *value)
{
	static const char * const values[] = {
		"Ace", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "Jack", "Queen", "King"
	};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(value, values[i]) == 0)
			return (i);
	}
	return (-1);
}

/**
 * deck_cmp - Comparator for qsort (by kind then by value)
 * @a: pointer to deck_node_t*
 * @b: pointer to deck_node_t*
 *
 * Return: negative if a<b, positive if a>b, 0 if equal
 */
static int deck_cmp(const void *a, const void *b)
{
	const deck_node_t *na = *(const deck_node_t * const *)a;
	const deck_node_t *nb = *(const deck_node_t * const *)b;
	int ra, rb;

	if (na->card->kind != nb->card->kind)
		return ((int)na->card->kind - (i

