#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 * using the insertion sort algorithm, in which nodes
 * will be checked one by one, and compared with already
 * sorted nodes to find their suitable position, so that
 * when the last node is reached, the list becomes sorted
 * @list: doubly linked list to be sorted
 *
 * Return: no return value
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *ex_temp, *node;

	if (list != NULL && *list != NULL)
		temp = (*list)->next;
	while (temp != NULL)
	{
		ex_temp = temp->prev;
		node = temp;
		while (ex_temp != NULL)
		{
			if (node->n < ex_temp->n)
			{
				if (ex_temp != *list)
					ex_temp->prev->next = node;
				node->prev->next = node->next;
				if (node->next != NULL)
					node->next->prev = node->prev;
				node->prev = ex_temp->prev;
				ex_temp->prev = node;
				node->next = ex_temp;
				if (ex_temp == *list)
					*list = node;
				print_list(*list);
			}
			ex_temp = ex_temp->prev;
		}
		temp = temp->next;
	}
}
