#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <iostream>
using namespace std;

class RedBlackTree
{
	public:
	RedBlackTree();
	~RedBlackTree();
	void insert(int i);
	void print_tree();
	void find_depth();
	void print_root(); //debugging
	void print_children_pub(); //debugging
	private:	
	class Node
	{
		public:
		Node* parent;
		Node* left;
		Node* right;
		int color; //0 = red, 1 = black
		int data;
		Node(int i, int c, Node* par): data(i), color(c), parent(par), left(NULL), right(NULL){}
	};
	Node* root;
	void destroy_tree(Node* destroy_me);
	void insert_internal(int i, Node* cur_node);
	void print_tree_internal(Node* print);
	void attempt_recolor(Node* current);
	void left_rotate(Node* Q);
	void right_rotate(Node* P);
	void swap_colors(Node* first, Node* second);
	int find_depth_internal(Node* current, int count);
	void print_children(Node* tree_root);
};

#endif
