#include "sort.h"
/**
 * swap_list - Swaps element in the doubly linked list
 * @head: The Head pointer
 * @node_a:The first node
 * @node_b: The second node
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
 * insertion_sort_list - Inserts elements into a list
 *	using the selection sort algorithm
 * @head: Points to null
 */

void insertion_sort_list(listint_t **head)
{
	listint_t *temp_store, *ptr;

	if (head == NULL || *head == NULL)
		return;
	tmp_store = (*head)->next;
	while (tmp_store != NULL)
	{
		for (ptr = tmp_store; ptr != *head && (ptr->n < ptr->prev->n);)
		{
			swap_list(head, &(ptr->prev), &ptr);
			print_list(*head);
		}
		tmp_store = tmp_store->next;
	}
}
