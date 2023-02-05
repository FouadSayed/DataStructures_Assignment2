
#include <bits/stdc++.h>

using namespace std;

struct Node {
  char data;
  Node *left, *right;
  Node(){}
  Node(char data) {
    this->data = data;
    left = right = NULL;
  }
};

void postorder(struct Node* myNode) {
  if (myNode == NULL)
    return;
  postorder(myNode->left);
  postorder(myNode->right);
  cout << myNode->data;
}
Node * buildTree(string & preorder, int preorderFirst,
                      int preorderEnd, string & inorder, int inorderFirst, int inorderEnd, map < char, int > & myMap) {
  if (preorderFirst > preorderEnd || inorderFirst > inorderEnd) return NULL;
  Node * root = new Node(preorder[preorderFirst]);
  int ONE_ELEMENT = myMap[root -> data];
  int NUM_OF_ELEMENTS = ONE_ELEMENT - inorderFirst;
  root -> left = buildTree(preorder, preorderFirst + 1, preorderFirst + NUM_OF_ELEMENTS, inorder,
  inorderFirst, ONE_ELEMENT - 1, myMap);
  root -> right = buildTree(preorder, preorderFirst + NUM_OF_ELEMENTS + 1, preorderEnd, inorder,
  ONE_ELEMENT + 1, inorderEnd, myMap);
  return root;
}

void printPostOrder(string  preorder, string  inorder) {
  int preorderFirst = 0, preorderEnd = preorder.size() - 1;
  int inorderFirst = 0, inorderEnd = inorder.size() - 1;
  map < char, int > myMap;
  for (int i = inorderFirst; i <= inorderEnd; i++) {
    myMap[inorder[i]] = i;
  }
cout<<"postorder of tree with inorder \""<<inorder<<"\" and preorder \""<<preorder<<"\" is \"";
  postorder(buildTree(preorder, preorderFirst, preorderEnd, inorder, inorderFirst, inorderEnd, myMap));
  cout<<"\"\n";

}


int main() {
    printPostOrder("ABFGC", "FBGAC");
    printPostOrder("ZBFGC", "FBGZC");
    printPostOrder("ABFYC", "FBYAC");
    printPostOrder("TMFGC", "FMGTC");
    printPostOrder("AYFXN", "FYXAN");

  return 0;}

