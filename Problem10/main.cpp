#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};

struct Node *NewNode(int data)
{
    Node * new_Node = new Node;
    new_Node->left = nullptr;
    new_Node->right = nullptr;
    new_Node->data = data;
    return new_Node;

}


struct Node * Insert(Node *root, int key)
{

    if (root == nullptr)
        return NewNode(key);

    if (root->data > key)
        root->left = Insert(root->left, key);

    else if (root->data < key)
        root->right = Insert(root->right, key);


    return root;
}


int sum(Node *root, int k, int &count)
{

    if (root == nullptr)

        return 0;
    if (count > k)
        return 0;


    int res = sum(root->left, k, count);
    if (count >= k)
        return res;

    res += root->data;

    count++;
    if (count == k)
        return res;
    return res + sum(root->right, k, count);
}


int sum(struct Node *root, int k)
{
    int count = 0;
  return sum(root, k, count);
}


int main()
{


    Node *root = nullptr;
    root = Insert(root, 54);
    root = Insert(root, 51);
    root = Insert(root, 49);
    root = Insert(root, 52);
    root = Insert(root, 75);
    root = Insert(root, 74);
    root = Insert(root, 85);
    int k = 3;
    cout <<"Sum of smallest elements is " << sum(root, k) <<endl;

    Node *rot = nullptr;
    rot = Insert(rot, 83);
    rot = Insert(rot, 72);
    rot = Insert(rot, 30);
    rot = Insert(rot, 52);
    rot = Insert(rot, 73);
    rot = Insert(rot, 45);
    rot = Insert(rot, 42);
    int ka = 2;
    cout <<"Sum of smallest elements is " << sum(rot, ka) <<endl;


    Node *ro = nullptr;
    ro = Insert(ro, 57);
    ro = Insert(ro, 1);
    ro = Insert(ro, 39);
    ro = Insert(ro, 2);
    ro = Insert(ro, 75);
    ro = Insert(ro, 4);
    ro = Insert(ro, 8);
    int kat = 6;
    cout <<"Sum of smallest elements is " << sum(ro, kat) <<endl;




    Node *r = nullptr;
    r = Insert(r, 90);
    r = Insert(r, 40);
    r = Insert(r, 43);
    r = Insert(r, 2);
    r = Insert(r, 7);
    r = Insert(r, 32);
    r = Insert(r, 87);
    int kath = 5;
    cout <<"Sum of smallest elements is " << sum(r, kath) <<endl;





    Node *r1 = nullptr;
    r1 = Insert(r1, 1);
    r1 = Insert(r1, 2);
    r1 = Insert(r1, 3);
    r1 = Insert(r1, 4);
    r1 = Insert(r1, 5);
    r1 = Insert(r1, 6);
    r1 = Insert(r1, 7);
    int kath1 = 4;
    cout <<"Sum of smallest elements is " << sum(r1, kath1) <<endl;
    return 0;
}


