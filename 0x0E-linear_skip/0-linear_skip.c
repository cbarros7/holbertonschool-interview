#include "search.h"


/**
 * linear_skip - function that finds a specific value in a skip list
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: pointer to the (first) node where value is located
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *slow = NULL, *fast = NULL;

	if (!list)
		return (NULL);

	slow = list;
	fast = list->express;

	/* Narrow down the search between slow->index and fast->index */
	while (fast)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       fast->index, fast->n);
		if (fast->n >= value)
			break;
		slow = fast;
		if (fast->express == NULL)
		{
			while (fast->next)
				fast = fast->next;
			break;
		}
		fast = fast->express;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	       slow->index, fast->index);

	/* Find the value in the [slow->index; fast->index] interval */
	while (slow && slow->index <= fast->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       slow->index, slow->n);
		if (slow->n == value)
			return (slow);
		slow = slow->next;
	}

	/* Return NULL if value is not present in list */
	return (NULL);
}
