/*
 * TUT117
 * Find if a tree is balanced or not. A tree is balanced
 * if none of the subtrees differ in height by more than 1
 *
 */
#include <stdio.h>
#include <assert.h>

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
} Node;

Node A={1,};
Node B={2,};
Node C={3,};
Node D={4,};
Node AB={5,&A,&B};
Node CD={6,&C,&D};
Node R = {7,&AB,&CD};

/* Finds the max and min path lengths of the leaf nodes
 * of a tree. We track max for in tree traversal. We track
 * min for out of tree traversal ie edges.
 */
void
find_max_min_rootplen(Node *r, int *min , int *max , int plen)
{
	if (r == NULL) {
		if((*min > plen)) {
			*min = plen;
		}
	}
	else {
		plen = plen + 1;
		if (*max < plen ) {
			*max = plen;
		}
		find_max_min_rootplen(r->left,min,max,plen);	
		find_max_min_rootplen(r->right,min,max,plen);	
	}	
}

int
is_balanced(Node *r)
{
	int min,max;
	min = 1000; //set to infinity.
	max = 0;
	find_max_min_rootplen(r, &min , &max, 0);
	//printf("\n min %d - max %d ",min,max);
	if ( (max - min) > 1 ) return 0;
	else return 1;
}

int
main(int argc , char **argv)
{
	assert(is_balanced(&A));
	assert(is_balanced(&AB));
	assert(is_balanced(&AB));
	assert(is_balanced(&AB));
	assert(is_balanced(&R));
	assert(is_balanced(&R));
	assert(is_balanced(&R));
	AB.right = NULL;
	assert(is_balanced(&R));
	R.right = NULL;
	assert(!is_balanced(&R));

}
