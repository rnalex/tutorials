#ifndef __TREE_ALGO__
#define __TREE_ALGO__
#include <iostream>
#include <memory>

using namespace std;
template <typename D>
struct TreeNode {
	D data;
	unique_ptr<TreeNode> left;
	unique_ptr<TreeNode> right;
	TreeNode(D indata):data(indata),left(nullptr),right(nullptr){};
};

template <typename T>
class Tree {
	public:
		Tree(){};
		virtual ~Tree(){};
	private:
		TreeNode<T> *
			SubtreeInsert(unique_ptr<TreeNode<T>> &subtree, const T data) {
				if (subtree.get() == nullptr) {
					cout << endl << "Inserting ... " << data;
					subtree = unique_ptr<TreeNode<T>>(new TreeNode<T>(data));
					return subtree.get();
				}
				else if (subtree->data > data) {
					return SubtreeInsert(subtree->left, data);
				}
				else if (subtree->data < data) {
					return SubtreeInsert(subtree->right,data);
				}
			}

		void
		SubtreeShow(const unique_ptr<TreeNode<T>> &subtree) {
			if (subtree.get() == nullptr) return;
			cout << endl << subtree->data;
			SubtreeShow(subtree->left);
			SubtreeShow(subtree->right);
		}
	public:
		TreeNode<T> *
			Insert(const T data) {
				return SubtreeInsert(_root,data);
			}

		TreeNode<T> * CommonAncestor(const unique_ptr<TreeNode<T>> &node, 
				const unique_ptr<TreeNode<T>> &nodeA,
				const unique_ptr<TreeNode<T>> &nodeB
				) {
			if (node.get() == nullptr) {
				return nullptr;
			}
			
			cout << "Visiting data ..." << node->data << endl;
			if (node->left == nodeA || node->right == nodeB)
			{
				cout << "Found data ..." << node->data << endl;
				return node.get();
			}
			TreeNode<T> * ltree = CommonAncestor(node->left,nodeA,nodeB);
			TreeNode<T> * rtree = CommonAncestor(node->right,nodeA,nodeB);
			if (ltree && rtree) {
				return node.get();
			}
			else {
				return ltree ? ltree : rtree;
			}
		}

		void
		Show() {
			SubtreeShow(_root);
		}
		
	private:
		unique_ptr<TreeNode<T>> _root;
};

#endif
#if 0
int
main(int argc , char **argv) 
{
	Tree<int> t;
	int six=6;
	int four=4;
	int two=2;
	int five=5;

	unique_ptr<TreeNode<int>> d4(t.Insert(four));
	unique_ptr<TreeNode<int>> d6(t.Insert(six));
	unique_ptr<TreeNode<int>> d2(t.Insert(two));
	unique_ptr<TreeNode<int>> d5(t.Insert(five));

	t.Show();
	TreeNode<int> *upi = t.CommonAncestor(d4,d2,d5); 	
	cout << "Answer" << upi->data; 	

	upi = t.CommonAncestor(d5,d2,d6); 	
	if (upi != nullptr) cout << "Answer" << upi->data; 	
	t.Show();
	d4.reset();
}
#endif
	
