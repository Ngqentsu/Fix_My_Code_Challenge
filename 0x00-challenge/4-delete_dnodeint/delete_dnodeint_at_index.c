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
	dlistint_t *saved_head = *head;
	dlistint_t *current = *head;
	unsigned int i;

	if (*head == NULL)
	  {
	    return (-1);
	  }
	if (index == 0)
	  {
	    *head = current->next;
	    if (current->next != NULL)
	      {
		current->next->prev = NULL;
	      }
	    free(current);
	    return (1);
	  }
	for (i = 0; i < index; i++)
	  {
	    if (current == NULL)
	      {
		*head = saved_head;
		return (-1);
	      }
	    current = current->next;
	  }
	if (current == NULL)
	  {
	    *head = saved_head;
	    return (-1);
	  }
	if (current->prev != NULL)
	  {
	    current->prev->next = current->next;
	  }
	if (current->next != NULL)
	  {
	    current->next->prev = current->prev;
	  }
	*head = saved_head;
	free(current);
	return (1);
}
