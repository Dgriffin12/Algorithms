#include "RedBlackTree.h"
#include <iostream>
using namespace std;

int main()
{
	RedBlackTree rbtree;
	rbtree.insert(10);
	rbtree.insert(20);
	rbtree.insert(30);
	rbtree.insert(15);
	rbtree.print_tree();
	rbtree.find_depth();
	rbtree.print_root();
	rbtree.print_children_pub();
	return 0;
}
