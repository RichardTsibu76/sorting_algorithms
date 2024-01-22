#include "sort.h"

/**
 * swap_list - Swaps elements
 * @head: Head pointer
 * @node_a: First node
 * @node_b: Second node
 */

void swap_list(listint_t **head, listint_t **node_a, listint_t **node_b)
{
	listint_t *a, *b;

	a = *node_a, b = *node_b;

	if (b->next != NULL)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	b->next = a;
	a->prev = b;
	if (a == *head)
		*head = b;
	else
		b->prev->next = b;
}
/**
 * insertion_sort_list - Inserts a node a node
 *	using the inserting sort of algorithm
 * @head: The head of the list that points to NULL
 */

void insertion_sort_list(listint_t **head)
{
	listint_t *tmp_store, *pt;

	if (head == NULL || *head == NULL)
		return;
	tmp_store = (*head)->next;
	while (tmp_store != NULL)
	{
		for (pt = tmp_store; pt != *head && (pt->n < pt->prev->n);)
		{
			swap_list(head, &(pt->prev), &pt);
			print_list(*head);
		}
		tmp_store = tmp_store->next;
	}
}
