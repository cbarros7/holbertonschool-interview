#include "lists.h"

/**
 * is_palindrome - function that checks if a singly linked list is a palindrome
 * @head: pointer to the list head
 * Return: 1 if list is palindrome, 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	int i = 0, j = 0;
	listint_t *current = NULL;
	int array[1000000];

	if (!head)
		return (1);
	if (!(*head))
		return (1);
	current = *head;
	while (current)
	{
		array[i] = current->n;
		current = current->next;
		i++;
	}
	for (j = 0; j < i; j++)
		if (array[j] != array[i - 1 - j])
			return (0);
	return (1);
}
