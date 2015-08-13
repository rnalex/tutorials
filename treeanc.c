/*
 * Find the highest common ancestor of 2 nodes in a tree
 * TUT112
 * Find out the node which has a different direction
 * for the data in nodes. Check if the subtrees have 
 * the required data.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Tnode {
	struct Tnode *left;
	struct Tnode *right;
	char  data;
} Tnode;

struct Tnode R,A,B,C,D,E,F,G,H,I;

Tnode R = {&A,&B,'R'};
Tnode A = {&C,&D,'A'};
Tnode B = {&E,&F,'B'};
Tnode C = {&G,&H,'C'};
Tnode D = {&I,NULL,'D'};
Tnode E = {NULL,NULL,'E'};
Tnode F = {NULL,NULL,'F'};
Tnode G = {NULL,NULL,'G'};
Tnode H = {NULL,NULL,'H'};
Tnode I = {NULL,NULL,'I'};
Tnode M = {NULL,NULL,'\n'}; //Marker


struct Tnode R1,A1,B1,C1,D1,E1,F1,G1,H1,I1;

Tnode R1 = {&A1,&B1,'A'+8};
Tnode A1 = {&C1,&D1,'A'+4};
Tnode B1 = {&E1,&F1,'A'+10};
Tnode C1 = {&G1,&H1,'A'+2};
Tnode D1 = {&I1,NULL,'A'+6};
Tnode E1 = {NULL,NULL,'A'+9};
Tnode F1 = {NULL,NULL,'A'+11};
Tnode G1 = {NULL,NULL,'A'+1};
Tnode H1 = {NULL,NULL,'A'+3};
Tnode I1 = {NULL,NULL,'A'+5};
Tnode M1 = {NULL,NULL,'\n'}; //Marker

#define MAX_QUEUE_SIZE (16)
#define QUEUE_MOD(index) (index & (MAX_QUEUE_SIZE-1))

Tnode *queue[MAX_QUEUE_SIZE +1];

int qtail = 0;
int qsize = 0;

inline int
empty_queue(Tnode **q)
{
	return qsize == 0;
}

inline int
full_queue(Tnode **q)
{
	return qsize == MAX_QUEUE_SIZE;
}

void
enqueue(Tnode **q, Tnode *data)
{
	if (full_queue(q)) {
		assert(!"Enough slots");
		return;
	}
	q[QUEUE_MOD(qtail+qsize)] = data;

	++qsize;
}


Tnode *
dequeue(Tnode **q)
{
	if (empty_queue(q)) {
		assert(!"Enough items");
	} else {
		int old_qtail=qtail;
		--qsize;
		qtail = QUEUE_MOD(qtail+1);
		return q[QUEUE_MOD(old_qtail)];
	}
}

void
show_queue(Tnode **q)
{
	int i;
	printf("\n----- qt %d qs %d",qtail,qsize);
	for(i=0; i<qsize; ++ i) {
		printf("\n%p",q[QUEUE_MOD(qtail+i)]);
	}
}

void
show_tree(Tnode *root)
{
	if (root) {
		enqueue(queue,root);
		enqueue(queue,&M);
	}
	struct Tnode *tnode;
	while (!empty_queue(queue)) {
		tnode = dequeue(queue);
		printf("%c",tnode->data);
		if (tnode->left) enqueue(queue,tnode->left);
		if (tnode->right) enqueue(queue,tnode->right);
		if ((tnode == &M) && !empty_queue(queue)) {
			enqueue(queue,&M);
		}
	}
}

Tnode *
FindANC(Tnode *root, char data1 , char data2)
{
	Tnode *tnode=root;
	Tnode *vnode1,*vnode2;
	if (root) {
		while (tnode) {
			printf("\n - %c",tnode->data);
			if (data1 > tnode->data) {
				vnode1 = tnode->right;
			}
			else {
				vnode1 = tnode->left;
			}

			if (data2 > tnode->data) {
				vnode2 = tnode->right;
			}
			else {
				vnode2 = tnode->left;
			}
			/* Lowest common ancestor points to 2 different directions */
			if (vnode1 == vnode2) {
				tnode = vnode1;	
			}
			else {
				return tnode && tnode->left && tnode->right ? tnode : NULL;
			}
		}
	}
	else return NULL;
}

Tnode *
FindNode(Tnode *root, char data)
{
	while (root) {
		if (root->data == data) return root;
		else if (root->data > data) {
			root = root->left;
		}
		else {
			root = root->right;
		}
	}
	return root;
}

int
main(int argc , char **argv)
{
	/* use power of 2 modulos */
	assert((MAX_QUEUE_SIZE & (MAX_QUEUE_SIZE-1)) == 0);
	//show_tree(&R);
	show_tree(&R1);
	printf("\nFound ANC %p %c",FindANC(&R1,'J','L'),FindANC(&R1,'J','L')->data);
	assert(FindNode(FindANC(&R1,'J','L'),'J') && (FindNode(FindANC(&R1,'J','L'),'L')));
	return 0;
}

