/*
 * RN Alex
 *
 * Copy a list which has two logical list
 * a) a traditional singly linked list linked (A) via the next field
 * b) another list B which uses some are made up of some of the
 *    elements of A and is linked using nextlink field
 *
 * The solution is to do the following
 * (a) copy A onto a new list C by traversing A. Replicate the nextlink field
 *     from A to C. 
 * (b) maintain a 1-1 relationship between A and C by using the nextlink field
 * of A to C  ie A[1].nextlink == C[1] for all nodes in A.
 *
 * (c)Traverse C through the nextlink which was the original relationship of 
 *  of linkded list B. Since there is a 1-1 correspondance between A->nextlink
 * and C we can restore the relationship which is similar to B. Restore the 
 * relationship in A via the nextfield.
 *
 * This implementation assumes |A| == |C|. If not we need to handle the
 * edge conditions.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct Node {
	unsigned int data;
	struct Node *next;
	struct Node *nextlink;
} Node;

struct Node A;
struct Node B;
struct Node C;
struct Node D;
struct Node E;

Node E= {5,NULL,&B };
Node D= {4,&E,&C};
Node C= {3,&D,NULL};
Node B= {2,&C,&D};
Node A= {1,&B,&E};

Node *list = &A;
Node *lcopy = NULL;

void show_list(Node *src)
{
	Node *trav = src;
	printf("\n-----------------------------------------");
	while(trav) {
		printf("\n %p %c %c", trav, 'A'+trav->data -1, trav->nextlink?'A'+trav->nextlink->data -1:'0');
		trav = trav->next;
	}
}

void copy_list(Node **src , Node **dst)
{
	Node *s,*sl,*d;
	s = *src;
	while(s) {
		d = (Node *)malloc(sizeof(Node));
		assert(d);
		*d = *s;
		if ( *dst == NULL) {
			*dst = d;
			d->next = NULL;
			sl = d;
		} else {
			sl->next = d;
			d->next = NULL;
			sl = d;
		}

		s->nextlink = d;  //save a copy of the link.
		s = s->next;
	}

	s = *src;
	d = *dst;
	while( s && d ) {
		Node *real_link;
		Node *copied_link;

		copied_link = d->nextlink;
		real_link = copied_link->nextlink;

		d->nextlink = real_link;
		s->nextlink = copied_link;

		s = s->next;
		d = d->nextlink;
	}
}


int
main(int argc , char **argv)
{
	show_list(list);
	copy_list(&list,&lcopy);
	show_list(lcopy);
	show_list(list);
}
