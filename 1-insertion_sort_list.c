#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @left: Pointer to the left node
 * @right: Pointer to the right node
 * @list: Pointer to the head of the list
 */
void swap_nodes(listint_t *left, listint_t *right, listint_t **list)
{
if (left->prev)
left->prev->next = right;
else
*list = right;

if (right->next)
right->next->prev = left;

left->next = right->next;
right->prev = left->prev;
left->prev = right;
right->next = left;
}

/**
 * insertion_sort_list - Using the Insertion sort algorithm.
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *insert;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

current = (*list)->next;
while (current)
{
insert = current;
while (insert->prev && insert->n < insert->prev->n)
{
swap_nodes(insert->prev, insert, list);
print_list(*list);  // Print the list after each swap
}
current = current->next;
}
}
