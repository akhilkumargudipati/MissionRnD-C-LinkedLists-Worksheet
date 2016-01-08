/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>
void swap(struct node *a, struct node *b);
struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head)
{
	int swapped, i;
	struct node *ptr1=head;
	struct node *lptr = NULL;

	/* Checking for empty list */
	if (ptr1 == NULL)
		return NULL;
	if (ptr1->next == NULL)
		return head;

	do
	{
		swapped = 0;
		ptr1 = head;

		while (ptr1->next != lptr)
		{
			if (ptr1->num > ptr1->next->num)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
	return head;
}
void swap(struct node *a, struct node *b)
{
	int temp = a->num;
	a->num = b->num;
	b->num = temp;
}