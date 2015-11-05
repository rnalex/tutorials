/*
 * Traverse a tree in level order
 * TUT109
 * Use a queue to record all the nodes in a tree.
 * The rule of recording is as follows.
 *    enqueue the root.
 * while (queue is non empty)
 *        dequeue node
 *        enque all children of node.
 *
 * We use a marker node to print the level information.
 * We add the marker for the last node in a level.
 * We figure out the last node if the examined node is 
 * a last node in its level.
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

int
main(int argc , char **argv)
{
	/* use power of 2 modulos */
	assert((MAX_QUEUE_SIZE & (MAX_QUEUE_SIZE-1)) == 0);
	show_tree(&R);

}

