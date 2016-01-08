/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
}*top, *temp;
void push(int data)
{
	if (top == NULL)
	{
		top = (struct node *)malloc(1 * sizeof(struct node));
		top->next = NULL;
		top->num = data;
	}
	else
	{
		temp = (struct node *)malloc(1 * sizeof(struct node));
		temp->next = top;
		temp->num = data;
		top = temp;
	}
}
struct node * numberToLinkedList(int N) {
	top = NULL;
	if (N<0)
		N *= -1;
	if (N == 0)
		push(0);
	else
		while (N > 0)
		{
		push(N % 10);
		N /= 10;
		}
	return top;
}
