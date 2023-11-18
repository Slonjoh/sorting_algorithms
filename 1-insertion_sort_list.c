#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers.
 * @list: Pointer to the head of the doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key;

	current = (*list)->next;

	if (!list || !(*list) || !((*list)->next))
		return;

	while (current != NULL)
	{
		key = current;

		while (key->prev != NULL && key->n < key->prev->n)
		{
			if (key->next != NULL)
				key->next->prev = key->prev;
			key->prev->next = key->next;
			key->next = key->prev;
			key->prev = key->prev->prev;

			if (key->prev != NULL)
				key->prev->next = key;

			if (key->next != NULL)
				key->next->prev = key;

			if (key->prev == NULL)
				*list = key;

			print_list(*list);
		}

		current = current->next;
	}
}
