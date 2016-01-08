/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) 
{
	int temp;
	struct node*temp1 = head;
	if (head == NULL||K<=0)
		return NULL;


	if (K == 1)
	{  
		struct node*temp, *ptr;
		ptr = head;
		while (ptr != NULL)
		{
			temp = ptr->next;
			free(ptr);
			ptr = temp;
		}
		return NULL;
	}
	else
	{
		int m = K - 1, n = 1;
		struct node *curr = head, *t;
		int count;

		// The main loop that traverses through the whole list
		while (curr)
		{
			// Skip M nodes
			for (count = 1; count<m && curr != NULL; count++)
				curr = curr->next;

			// If we reached end of list, then return
			if (curr == NULL)
				return head;

			// Start from next node and delete N nodes
			t = curr->next;
			for (count = 1; count <= n && t != NULL; count++)
			{
				struct node *temp = t;
				t = t->next;
				free(temp);
			}
			curr->next = t; // Link the previous list with remaining nodes

			// Set current pointer for next iteration
			curr = t;
		}
		return head;
	}
	
}