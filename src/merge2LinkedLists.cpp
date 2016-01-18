/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node * head = NULL;
	struct node * last = head;
	struct node *temp;
	while (head1 != NULL && head2 != NULL) {
		if (head1->num < head2->num) {
			temp = head1;
			head1 = head1->next;
		}
		else {
			temp = head2;
			head2 = head2->next;
		}
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			last = temp;
		}
		else {
			last->next = temp;
			last = last->next;
		}
	}
	if (head1 == NULL && head2 != NULL) {
		last->next = head2;
	}
	else {
		last->next = head1;
	}
	return head;
}
