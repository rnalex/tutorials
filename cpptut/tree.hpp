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
	~TreeNode(){}
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
					//cout << endl << "Inserting ... " << data;
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
			//cout << endl << subtree->data;
			SubtreeShow(subtree->left);
			SubtreeShow(subtree->right);
		}


		bool 
		_FindCommonAncestor(const unique_ptr<TreeNode<T>> &subtree,
				T &ancestor, 
				const T & nodeA,
				const T & nodeB
			      ) {
			if (subtree.get() == nullptr) {
				return nullptr;
			}

			//cout << "Visiting data ..." << subtree->data << endl;
			if (subtree->data == nodeA || subtree->data == nodeB)
			{
				//cout << "Found data ..." << node->data << endl;
				ancestor = subtree->data;
				return true;
			}
			bool ltree = _FindCommonAncestor(subtree->left,ancestor,nodeA,nodeB);
			bool rtree = _FindCommonAncestor(subtree->right,ancestor,nodeA,nodeB);
			if (ltree && rtree) {
				ancestor = subtree->data;
				return true;
			}
			else {
				return false;
			}
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
			
			//cout << "Visiting data ..." << node->data << endl;
			if (node->left == nodeA || node->right == nodeB)
			{
				//cout << "Found data ..." << node->data << endl;
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

		bool 
		FindCommonAncestor( T & ancestor, 
				const T & nodeA,
				const T & nodeB
				) {

			return _FindCommonAncestor(_root,ancestor,nodeA,nodeB);
		}

		void
		Show() {
			SubtreeShow(_root);
		}
		
	private:
		unique_ptr<TreeNode<T>> _root;
};

#endif
