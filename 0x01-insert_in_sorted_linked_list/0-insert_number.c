#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * new_node - makes new node of listint_t type
 * @number: new node value
 * Return: address of new node
 */
listint_t *new_node(int number)
{
  listint_t *new;

  new = malloc(sizeof(listint_t));
  new->n = number;
  new->next = NULL;

  return (new);
}


/**
 * insert_node - inserts a node into a sorted singly linked list
 * @head: double pointer to head of linked list
 * @number: integer to insert into list
 * Return: address of new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
  listint_t *beg;
  listint_t *i;
  listint_t *new;

  beg = *head;
  i = *head;
  new = new_node(number);

  if (!head || !new)
    return (NULL);
  if (!*head)
    {
      *head = new;
      return (new);
    }
  if (new->n < (*head)->n)
    {
      new->next = (*head);
      *head = new;
      return (new);
    }
  while (beg && *head)
    {
      if (beg->next == NULL)
      {
      beg->next = new;
      new->next = NULL;
      }
      if (beg->n > new->n)
      {
      new->next = beg;
      i->next = new;
      break;
      }
      i = beg;
      beg = beg->next;
    }
  return (new);
}
