#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <chrono>
#include <queue>
using namespace std;


#define boom ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
#define endl "\n";

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};


Node* new_node(int val)
{
	Node* n = new Node;
	n->data = val;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void flip(Node* node)
{
	if (node == NULL)
	{
		return;
	}
	else
	{
		 Node* temp;

		
		flip(node->left);
		flip(node->right);

		
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}

void inorder( Node* node)
{
	if (node == NULL)
	{
		return;
	}

	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right);
}

int main()
{
	struct Node* root1 = new_node(1);
	root1->left = new_node(2);
	root1->right = new_node(3);
	root1->left->left = new_node(4);
	root1->left->right = new_node(5);

	cout << "Test case 1" << endl;
	cout << endl;
	cout << "The original Tree" << endl;
	cout << endl;
	inorder(root1);
	cout << endl;
	cout << endl;

	flip(root1);

	cout << "The New Tree"<< endl;
	cout << endl;
	inorder(root1);
	cout << endl;
	cout << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << endl;


	struct Node* root2 = new_node(5);
	root2->left = new_node(11);
	root2->right = new_node(9);
	root2->left->left = new_node(15);
	root2->right->right = new_node(3);

	cout << "Test case 2" << endl;
	cout << endl;

	cout << "The original Tree" << endl;
	cout << endl;
	inorder(root2);
	cout << endl;
	cout << endl;


	flip(root2);

	cout << "The New Tree" << endl;
	cout << endl;
	inorder(root2);
	cout << endl;
	cout << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << endl;
	


	struct Node* root3 = new_node(1);
	root3->right = new_node(6);
	root3->right->right = new_node(9);
	root3->left = new_node(10);
	root3->left->right = new_node(5);


	cout << "Test case 3" << endl;
	cout << endl;

	cout << "The original Tree" << endl;
	cout << endl;
	inorder(root3);
	cout << endl;
	cout << endl;

	flip(root3);

	cout << "The New Tree" << endl;
	cout << endl;
	inorder(root3);
	cout << endl;
	cout << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << endl;

	struct Node* root4 = new_node(12);
	root4->left = new_node(9);
	root4->right = new_node(7);
	root4->left->left = new_node(1);
	root4->left->right = new_node(3);

	cout << "Test case 4" << endl;
	cout << endl;

	cout << "The original Tree" << endl;
	cout << endl;
	inorder(root4);
	cout << endl;
	cout << endl;

	flip(root4);

	cout << "The New Tree" << endl;
	cout << endl;
	inorder(root4);
	cout << endl;
	cout << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << endl;
	
	struct Node* root5 = new_node(20);
	root5->right = new_node(13);
	root5->left = new_node(11);
	root5->left->right = new_node(4);
	root5->right->right = new_node(5);

	cout << "Test case 5" << endl;
	cout << endl;

	cout << "The original Tree" << endl;
	cout << endl;
	inorder(root5);
	cout << endl;
	cout << endl;

	flip(root5);

	cout << "The New Tree" << endl;
	cout << endl;
	inorder(root5);
	cout << endl;
	cout << endl;


	return 0;
}
