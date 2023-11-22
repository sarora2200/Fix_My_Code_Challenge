#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	dlistint_t *temp;

	if (*head == NULL)
		return (-1);

	/* Case: Deleting the first node */
	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		if (*head != NULL)
			(*head)->prev = NULL;
		return (1);
	}

	/* Traverse to the node at index */
	for (unsigned int i = 0; i < index && current != NULL; i++)
		current = current->next;

	/* Check if the index is beyond the end of the list */
	if (current == NULL)
		return (-1);

	/* Adjust the prev and next pointers */
	current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);
	return (1);
}
