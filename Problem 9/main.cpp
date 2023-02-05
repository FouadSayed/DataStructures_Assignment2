#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left , *right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};

class BST{
public:
    Node *root;

    BST(){
        root=NULL;
    }

    Node *insert(int item){
        Node *node=new Node(item);
        return node;
    }
    void inorder(Node *pnode){//left->root->right
        if(pnode == NULL)
            return;
        inorder(pnode->left);
        cout<<pnode->data<<"\t";
        inorder(pnode->right);
    }
    bool foldable(Node *pnode1  , Node *pnode2){
            if (pnode1 == NULL && pnode2 == NULL)
                return true;
            if (pnode1 != NULL && pnode2 != NULL) {
                return foldable(pnode1->left, pnode2->right) && foldable(pnode1->right, pnode2->left);
            }
            return false;
    }
};
int main() {
    //first test case
    BST btree1;
    btree1.root = btree1.insert(1);
    btree1.root->left = btree1.insert(4);
    btree1.root->left->right = btree1.insert(5);
    btree1.root->right = btree1.insert(2);
    btree1.root->right->left = btree1.insert(3);
    if(btree1.root == NULL)
        cout<<"not foldabale"<<endl;
    else {
        if (btree1.foldable(btree1.root->left, btree1.root->right)) {
            cout << "the tree is foldable" << endl;
        } else
            cout << "not foldabale" << endl;
    }
    cout<<"tree is "<<endl;
    btree1.inorder(btree1.root);
    cout<<endl<<"------------------------------------------------------"<<endl;
    //----------------------------------------------------------------------
    //second test case
    BST btree2;
    btree2.root = btree2.insert(1);
    btree2.root->left = btree2.insert(2);
    btree2.root->left->left = btree2.insert(4);
    btree2.root->right = btree2.insert(3);
    btree2.root->right->right = btree2.insert(5);
    if(btree2.root == NULL)
        cout<<"not foldabale"<<endl;
    else {
        if (btree2.foldable(btree2.root->left, btree2.root->right)) {
            cout << "the tree is foldable" << endl;
        } else
            cout << "not foldabale" << endl;
    }
    cout<<"tree is "<<endl;
    btree2.inorder(btree2.root);
    cout<<endl<<"------------------------------------------------------"<<endl;
    //----------------------------------------------------------------------
    //third test case
    BST btree3;
    btree3.root = btree3.insert(1);
    btree3.root->left = btree3.insert(2);
    btree3.root->left->left = btree3.insert(4);
    btree3.root->left->right = btree3.insert(6);
    btree3.root->right = btree3.insert(3);
    btree3.root->right->right = btree3.insert(5);
    if(btree3.root == NULL)
        cout<<"not foldabale"<<endl;
    else {
        if (btree3.foldable(btree3.root->left, btree3.root->right)) {
            cout << "the tree is foldable" << endl;
        } else
            cout << "not foldabale" << endl;
    };
    cout<<"tree is "<<endl;
    btree3.inorder(btree3.root);
    cout<<endl<<"------------------------------------------------------"<<endl;
    //----------------------------------------------------------------------
    //fourth test case
    BST btree4;
    btree4.root = btree4.insert(1);
    btree4.root->left = btree4.insert(2);
    btree4.root->left->left = btree4.insert(4);
    btree4.root->left->right = btree4.insert(6);
    btree4.root->right = btree4.insert(3);
    btree4.root->right->right = btree4.insert(5);
    btree4.root->right->left = btree4.insert(7);
    if(btree4.root == NULL)
        cout<<"not foldabale"<<endl;
    else {
        if (btree4.foldable(btree4.root->left, btree4.root->right)) {
            cout << "the tree is foldable" << endl;
        } else
            cout << "not foldabale" << endl;
    }
    cout<<"tree is "<<endl;
    btree4.inorder(btree4.root);
    cout<<endl<<"------------------------------------------------------"<<endl;
    //----------------------------------------------------------------------
    //fifth test case
    BST btree5;
    if(btree5.root == NULL)
        cout<<"not foldabale"<<endl;
    else {
        if (btree5.foldable(btree5.root->left, btree5.root->right)) {
            cout << "the tree is foldable" << endl;
        } else
            cout << "not foldabale" << endl;
        cout << "tree is " << endl;
    }
    btree5.inorder(btree5.root);
}