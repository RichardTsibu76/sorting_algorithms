#include "sort.h"

/**
 * swap_list -This function swaps two nodes in a list
 * @head: A pointer
 * @node_a: This points to the first node
 * @node_b: Points to the second node
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
 * cocktail_sort_list - This is funtion for the sorting type
 * @head: A pointer
 * Return: Does not return
 */
void cocktail_sort_list(listint_t **head)
{
	bool swapped = false;
	listint_t *tmp_store = *head;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	do {
		for (; tmp_store->next;)
		{
			if (tmp_store->n > tmp_store->next->n)
			{
				swap_list(head, &tmp_store, &(tmp_store->next));
				print_list(*head);
				swapped = true;
			}
			else
				tmp_store = tmp_store->next;
		}
		if (swapped == false)
			break;/*This is an array to work correctly in order*/
		swapped = false;
		for (; tmp_store->prev;)
		{
			if (tmp_store->n < tmp_store->prev->n)
			{
				swap_list(head, &(tmp_store->prev), &tmp_store);
				print_list(*head);
				swapped = true;
			}
			else
				tmp_store = tmp_store->prev;
		}
	} while (swapped);
}
