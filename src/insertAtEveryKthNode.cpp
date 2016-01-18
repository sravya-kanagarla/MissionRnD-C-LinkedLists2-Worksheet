/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL)
		return NULL;
	struct node *iter = head;
	struct node *newNode;
	int i;
	while (iter != NULL) {
		for (i = K - 1; i > 0 && iter != NULL; i--) {
			iter = iter->next;
		}
		if (iter == NULL)
			break;
		newNode = (struct node *) malloc(sizeof(struct node));
		newNode->num = K;
		newNode->next = iter->next;
		iter->next = newNode;
		iter = newNode->next;
	}
	return head;
}
