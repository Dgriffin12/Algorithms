#ifndef MYBTREE_H
#define MYBTREE_H
#include <iostream>
using namespace std;

class MyTree
{
	private:
		int levels;
		class Node //internal node class, holds integer values in the tree.
		{
			public:			
			int data;
			Node* left;
			Node* right;
			Node(int i) : data(i), left(NULL), right(NULL){}
			
		};

		Node* root;
		Node* search(int i, Node* start);
		Node* search_for_deletion(int i, Node* start);
		Node* find_min(Node* current_node);
		void remove_node(int i, Node* start);
		void print_tree_internal(Node* print);
		void destroy_tree(Node* to_destroy);
		void add_node_internal(int i, Node* cur_node, int depth);
	public:
		MyTree();
		~MyTree();
		void print_root(); //debugging
		void add_node(int i);
		void print_tree();
		void print_levels();
		void remove_node_pub(int i);
		
};

#endif
