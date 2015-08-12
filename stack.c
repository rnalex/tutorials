/*
 * Implement a stack with max operation in O(n)
 * TUT110
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_STACK_SIZE (16)

typedef struct StackNode {
	int data;
	int max;
} StackNode;

StackNode *stack[MAX_STACK_SIZE +1];

int stack_start = 0;
int stack_size = 0;

inline int
empty_stack(StackNode **s)
{
	return stack_size == 0;
}

inline int
full_stack(StackNode **s)
{
	return stack_size == MAX_STACK_SIZE;
}

inline StackNode *
peek(StackNode **s)
{
	assert(!empty_stack(s));	
	return(s[(stack_start+stack_size)-1]);
}
inline int
max(StackNode **s)
{
	assert(!empty_stack(s));
	return(peek(s)->max);
}
void
push(StackNode **s, int data)
{
	if (full_stack(s)) {
		assert(!"Enough slots");
		return;
	}

	StackNode * sn = (StackNode *)malloc(sizeof(StackNode));
	assert(sn);
	sn->data = data;
	sn->max = data;
	if (empty_stack(s)) {
		sn->max = data;
	}
	else if (sn->max < peek(stack)->max ) {
		sn->max = peek(stack)->max;
	}
	s[(stack_start+stack_size)] = sn;

	++stack_size;
}

StackNode *
pop(StackNode **s)
{
	if (empty_stack(s)) {
		assert(!"Enough items");
	} else {
		--stack_size;
		return s[(stack_start+stack_size+1)];
	}
}

void
show_stack(StackNode **s)
{
	int i;
	printf("\n----- st %d ss %d",stack_start,stack_size);
	for(i=0; i<stack_size; ++ i) {
		printf("\n%d ",s[(stack_start+i)]->data);
		printf("-- %d ",s[(stack_start+i)]->max);
	}
}
int
main(int argc , char **argv)
{
	/* use power of 2 modulos */
	assert((MAX_STACK_SIZE & (MAX_STACK_SIZE-1)) == 0);
	push(stack,5);
	push(stack,7);
	push(stack,2);
	show_stack(stack);
	pop(stack);
	pop(stack);
	show_stack(stack);
	return 0;
}

