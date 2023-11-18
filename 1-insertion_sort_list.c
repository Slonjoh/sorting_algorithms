#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers.
 * @list: Pointer to the head of the doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		tmp = current;

		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			prev = tmp->prev;
			prev->next = tmp->next;

			if (tmp->next != NULL)
				tmp->next->prev = prev;
			tmp->next = prev;
			tmp->prev = prev->prev;
			prev->prev = tmp;

			if (tmp->prev == NULL)
				*list = tmp;
			else
				tmp->prev->next = tmp;

			print_list(*list);
		}

		current = current->next;
	}
}
