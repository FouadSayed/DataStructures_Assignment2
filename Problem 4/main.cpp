#include <iostream>
#include<algorithm>
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

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left),
        right(right) {}
};


class Solution
{
public:



    bool mirror(struct TreeNode* node1, struct TreeNode* node2)
    {
        if (node1 == NULL && node2 == NULL)
        {
            return true;
        }

        if ((node1 && node2) && (node1->val == node2->val))
        {
            return (mirror(node1->left, node2->right) && mirror(node1->right, node2->left));
        }
        return false;
    }
    bool isSymmetric(struct TreeNode* root) {

        if (root == NULL)
        {
            return true;
        }
        else
        {
            return mirror(root->left, root->right);
        }
    }
};


int main() {
    TreeNode* obj1 = new TreeNode(1);
    obj1->left = new TreeNode(2);
    obj1->right = new TreeNode(2);
    obj1->left->left = new TreeNode(3);
    obj1->left->right = new TreeNode(4);
    obj1->right->left = new TreeNode(4);
    obj1->right->right = new TreeNode(3);
    Solution x1;

    cout << "Test Case 1 :  ";
    if (x1.isSymmetric(obj1))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    TreeNode* obj2 = new TreeNode(1);
    obj2->left = new TreeNode(2);
    obj2->right = new TreeNode(2);
    obj2->left->left = new TreeNode(NULL);
    obj2->left->right = new TreeNode(3);
    obj2->right->left = new TreeNode(NULL);
    obj2->right->right = new TreeNode(3);
    Solution x2;
    cout << "Test Case 2 :  ";
    if (x2.isSymmetric(obj2))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }



    TreeNode* obj3 = new TreeNode(1);
    obj3->left = new TreeNode(4);
    obj3->right = new TreeNode(2);
    obj3->left->left = new TreeNode(NULL);
    obj3->left->right = new TreeNode(3);
    obj3->right->left = new TreeNode(5);

    Solution x3;
    cout << "Test Case 3 :  ";
    if (x3.isSymmetric(obj3))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }


    TreeNode* obj4 = new TreeNode(8);
    obj4->left = new TreeNode(7);
    obj4->right = new TreeNode(7);
    obj4->left->left = new TreeNode(1);
    obj4->left->right = new TreeNode(3);
    obj4->right->left = new TreeNode(3);
    obj4->right->right = new TreeNode(1);
    cout << "Test Case 4 :  ";
    Solution x4;
    if (x4.isSymmetric(obj4))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }


    TreeNode* obj5 = new TreeNode(11);
    obj5->right = new TreeNode(4);
    obj5->left = new TreeNode(2);
    obj5->right->left = new TreeNode(NULL);
    obj5->left->left = new TreeNode(2);

    Solution x5;
    cout << "Test Case 5 :  ";
    if (x5.isSymmetric(obj5))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }









    return 0;
}