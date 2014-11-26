#include "RedBlackTree.h"

//Constructor, initialize root to NULL.
RedBlackTree::RedBlackTree() : root(NULL)
{

}

//Destructor, calls destroy_tree, which will recursively destroy the tree starting at root.
RedBlackTree::~RedBlackTree()
{
	if(root)
	{
		destroy_tree(root);
	}
}

//function to recursively destroy the tree.
void RedBlackTree::destroy_tree(Node* destroy_me)
{
	if(destroy_me)
	{
		destroy_tree(destroy_me->left);
		destroy_tree(destroy_me->right);
		delete destroy_me;
	}
}

//wrapper for private insert function
void RedBlackTree::insert(int i)
{
	insert_internal(i, root);
}

//private insert function
void RedBlackTree::insert_internal(int i, Node* cur_node)
{
	if(!root)
	{
		root = new Node(i, 1, NULL); //insert black root node.
	}else if(cur_node)
	{
		if(!cur_node->left && i < cur_node->data)
		{
			cur_node->left = new Node(i, 0, cur_node);
			attempt_recolor(cur_node->left);
		}else if(!cur_node->right && i >= cur_node->data)
		{
			cur_node->right = new Node(i, 0, cur_node);
			attempt_recolor(cur_node->right);
		}else if(cur_node->left && i < cur_node->data)
		{
			insert_internal(i, cur_node->left);
		}else if(cur_node->right && i >= cur_node->data)
		{
			insert_internal(i, cur_node->right);
		}
	}
}

void RedBlackTree::attempt_recolor(Node* current)
{
	if(current->parent && current->parent->parent)
	{
		Node* g_parent = current->parent->parent;
		Node* uncle = NULL;
		int uncle_color = 1;
		if(g_parent->left && g_parent->left != current->parent)
		{
			uncle = g_parent->right;
			uncle_color = uncle->color;			 
		}else if(g_parent->right && g_parent->right != current->parent)
		{
			uncle = g_parent->left;
			uncle_color = uncle->color;
		}
		if(uncle_color == 0)
		{
			current->parent->color = 1;
			uncle->color = 1;
			g_parent->color = 0;
			attempt_recolor(g_parent);
		}else if(uncle_color == 1)
		{
			Node* parent = current->parent;
			if((current == current->parent->left) && (current->parent == g_parent->left))
			{
				//p = left child ... cur = left child
				//RIGHT ROTATE G_PARENT + SWAP COLORS ON G_PARENT AND PARENT
				right_rotate(current->parent);
				swap_colors(g_parent, current->parent);
			}else if((current == current->parent->right) && (current->parent == g_parent->left))
			{
				//p = left child ... cur = right child
				//LEFT ROTATE PARENT + LEFTLEFT CASE
				left_rotate(current);
				right_rotate(current);
				swap_colors(g_parent, current->parent);
			}else if((current == current->parent->right) && (current->parent == g_parent->right))
			{
				//p = right child ... cur = right child
				//LEFT ROTATE G_PARENT, SWAP COLORS ON G_PARENT AND PARENT
				left_rotate(current->parent);
				swap_colors(g_parent, current->parent);
			}else if((current == current->parent->left) && (current->parent == g_parent->right))
			{
				//p = right child ... cur = left child
				//RIGHT ROTATE PARENT + RIGHTRIGHT CASE
				right_rotate(current);
				left_rotate(current);
				swap_colors(g_parent, current->parent);
			}
		}
	}
}

void RedBlackTree::swap_colors(Node* first, Node* second)
{
	int temp_color;
	temp_color = first->color;
	first->color = second->color;
	second->color = temp_color;
}
void RedBlackTree::print_tree()
{
	print_tree_internal(root);
}

void RedBlackTree::print_tree_internal(Node* print)
{
	if(print)
	{
		print_tree_internal(print->left);
		cout << print->data << endl;
		print_tree_internal(print->right);
	}
}

void RedBlackTree::right_rotate(Node* P)  //modeled after illustration section of en.wikipedia.org/wiki/Tree_rotation
{
	Node* B = P->right;
	Node* Q = P->parent;
	if(Q == root)
	{
		root = P;
	}
	P->parent = Q->parent;
	Q->parent = P;
	Q->left = B;
	P->right = Q;
}

void RedBlackTree::left_rotate(Node* Q) //modeled after illustration section of en.wikipedia.org/wiki/Tree_rotation
{
	Node* B = Q->left;
	Node* P = Q->parent;
	if(P == root)
	{
		root = Q;
	}
	Q->parent= P->parent;
	P->parent = Q;
	P->right = B;
	Q->left = P;
}
void RedBlackTree::find_depth()
{
	cout << "depth is: " << find_depth_internal(root, 0) << endl;
}
int RedBlackTree::find_depth_internal(Node* current, int count)
{
	int left_side = 0;
	int right_side = 0;
	if(current)
	{
		count++;
		left_side = find_depth_internal(current->left, count);
		right_side = find_depth_internal(current->right, count);
		return max(left_side, right_side);
	}
	return count;
}

//debugging
void RedBlackTree::print_root()
{
	cout << "Root = " << root->data << endl;
}
//debugging
void RedBlackTree::print_children_pub()
{
	print_children(root);
}
//debugging
void RedBlackTree::print_children(Node* tree_root)
{
	if(tree_root->left)
	{
		cout << "Left: " << tree_root->left->data << endl;
	}else
	{
		cout << "Left: NULL" << endl;
	}
	if(tree_root->right)
	{
		cout << "Right: " << tree_root->right->data << endl;
	}else
	{
		cout << "Right: NULL" << endl;
	}
}
//for depth function
int max(int first, int second)
{
	if(first > second)
	{
		return first;
	}else //opposite above OR EQUAL
	{
		return second;
	}
}
