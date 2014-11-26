#include <iostream>
#include "myBtree.h"
using namespace std;

int main()
{
	MyTree tree;
	tree.add_node(8);
	tree.add_node(3);
	tree.add_node(10);
	tree.remove_node_pub(8);
	tree.print_root();
	tree.print_tree();
//	tree.print_levels();
	return 0;
}
