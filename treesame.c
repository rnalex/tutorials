#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
}Node;

	bool 
subtree_check(Node *root, int val)
{
	if (root == NULL) {
		return true;
	}
	if (root->left == NULL && 
			root->right == NULL &&
			root->data == val) {
		return true;
	}
	else if (root->left && root->right) {
		return (subtree_check(root->left,val) &&
				subtree_check(root->right,val));
	}
	else if (root->left) {
		return subtree_check(root->left,val);
	}
	else if (root->right) {
		return subtree_check(root->right,val);
	}	
}

	bool
is_same_treeval(Node *root )
{
	if (root == NULL ) return true;
	else subtree_check(root,root->data);
}

Node l0l={3,};
Node l0r={3,};
Node r0={3,};
Node l0={3,&l0l,&l0r};
Node r={3,&l0,&r0};

	int
main()
{
	printf("\n %s ",is_same_treeval(&r) ? "same" : "diff");
	r0.data=4;
	printf("\n %s ",is_same_treeval(&r) ? "same" : "diff");
	r0.data=3;
	printf("\n %s ",is_same_treeval(&r) ? "same" : "diff");
	l0l.data=1;
	printf("\n %s ",is_same_treeval(&r) ? "same" : "diff");
}
