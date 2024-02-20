#include "sort.h"

/**
 * swap2nodes - Swaps 2 nodes of a doubly likned list
 * @head: Pointer to pointer to head of list
 * @node1: Pointer to the 1st node
 * @node2: Pointer to the 2nd node
 *
 * Return: Always (0) success
 */

void swap2nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order.
 * @list: Double pointer to the head of the linked list.
 *
 * Description: This function sorts the doubly linked list in ascending order
 * After each swap operation, the function prints the list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *node, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		node = current->prev;
		while (node != NULL && current->n < node->n)
		{
			swap2nodes(list, &node, current);
			print_list(*list);
		}
	}
}
