/*
 * TUT116
 * Find if a subtree has a path costing x
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


int
has_path_with_cost(Node *r , int cost)
{
	if (r == NULL) return 0;

	if (r->data == cost) return 1;

	return (has_path_with_cost(r->left,cost-r->data)||
			has_path_with_cost(r->right,cost-r->data));
}

int
main(int argc , char **argv)
{
	assert(has_path_with_cost(&A,1));
	assert(has_path_with_cost(&AB,6));
	assert(has_path_with_cost(&AB,7));
	assert(!has_path_with_cost(&AB,8));
	assert(has_path_with_cost(&R,16));
	assert(has_path_with_cost(&R,17));
	assert(!has_path_with_cost(&R,18));

}
