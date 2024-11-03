#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Definition for a doubly linked list node */
typedef struct listint_s
{
int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

/* Function prototypes for sorting algorithms */
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

/* Helper functions for list manipulation and printing */
listint_t *create_listint(const int *array, size_t size);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

#endif /* SORT_H */
