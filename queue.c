/*
 * Implement a queue based on an array
 * TUT108
 * A queue can be thought of as an infinite
 * array with the starting position known and the
 * size of the queue known. Full and empty states are
 * inferred from qsize. Enqueue and Dequeue positions
 * are inferred using modulo operation on the starting
 * or tail position of the queue.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_QUEUE_SIZE (4)
#define QUEUE_MOD(index) (index & (MAX_QUEUE_SIZE-1))

int queue[MAX_QUEUE_SIZE +1];

int qtail = 0;
int qsize = 0;

inline int
empty_queue(int *q)
{
	return qsize == 0;
}

inline int
full_queue(int *q)
{
	return qsize == MAX_QUEUE_SIZE;
}

void
enqueue(int *q, int data)
{
	if (full_queue(q)) {
		assert(!"Enough slots");
		return;
	}
	q[QUEUE_MOD(qtail+qsize)] = data;

	++qsize;
}


int
dequeue(int *q)
{
	if (empty_queue(q)) {
		assert(!"Enough items");
	} else {
		--qsize;
		qtail = QUEUE_MOD(qtail+1);
		return q[QUEUE_MOD(qtail+qsize+2)];
	}
}

void
show_queue(int *q)
{
	int i;
	printf("\n----- qt %d qs %d",qtail,qsize);
	for(i=0; i<qsize; ++ i) {
		printf("\n%d",q[QUEUE_MOD(qtail+i)]);
	}
}
int
main(int argc , char **argv)
{
	/* use power of 2 modulos */
	assert((MAX_QUEUE_SIZE & (MAX_QUEUE_SIZE-1)) == 0);
	enqueue(queue,1);
	enqueue(queue,2);
	enqueue(queue,3);
	enqueue(queue,4);
	show_queue(queue);
	dequeue(queue);
	enqueue(queue,5);
	dequeue(queue);
	enqueue(queue,6);
	dequeue(queue);
	enqueue(queue,7);
	show_queue(queue);
	dequeue(queue);
	enqueue(queue,8);
	dequeue(queue);
	enqueue(queue,9);
	dequeue(queue);
	enqueue(queue,10);
	//enqueue(queue,10); //overflow
	show_queue(queue);
}

