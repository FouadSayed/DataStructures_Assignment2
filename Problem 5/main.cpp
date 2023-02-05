#include <iostream>
#include <iomanip>

using namespace std;
struct Node {

    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left),right(right) {}
    Node(int i, int i1, int i2) {}
};
Node* newNode(int data)
{
    Node* Node = new struct Node();
    Node->val = data;
    Node->left = nullptr;
    Node->right = nullptr;

    return(Node);
}
class Solution {
public:
    struct Node *Insert(Node *r, int item) {
        if (r == nullptr) {
            Node *newnode = new Node(item);
            r = newnode;
        } else if (item < r->val) {
            r->left = Insert(r->left, item);
        } else {
            r->right = Insert(r->right, item);
        }
        return r;
    }

    void Preorder(Node *r) {
        if (r == nullptr) {
            return;
            cout << r->val << endl;
            Preorder(r->left);
            Preorder(r->right);
        }
    }


    bool IsSameTree(Node *p, Node *q) {
        bool f= true;
        if (p== nullptr and q== nullptr){
            return f;
        }
        else if (p!= nullptr and q != nullptr){

            if (p->val==q->val and IsSameTree(p->left,q->left) and IsSameTree(p->right,q->right)){
                return f;
            }
        }
        else {
            return false;
        }
    }

};
int main() {
    Solution m ;
    Node*l = newNode(8);
    m.Insert(l,4);
    m.Insert(l,6);
    m.Insert(l,7);
    m.Preorder(l);

    Solution n;
    Node*k= newNode(8);
    n.Insert(k,4);
    n.Insert(k,6);
    n.Insert(k,7);
    n.Preorder(k);
    Solution p;
    if (p.IsSameTree(l,k)){cout<< "true"<<endl;}
    else{cout<<"false"<<endl;}



    Solution w ;
    Node*qq = newNode(8);
    w.Insert(qq,4);
    w.Insert(qq,NULL);
    w.Insert(qq,7);
    w.Preorder(qq);

    Solution o;
    Node*tt= newNode(8);
    o.Insert(tt,4);
    o.Insert(tt,6);
    o.Insert(tt,7);
    o.Preorder(tt);
    Solution pp;
    if (pp.IsSameTree(qq,tt)){cout<< "true"<<endl;}
    else{cout<<"false"<<endl;}
    Solution s ;
    Node*q = newNode(8);
    s.Insert(q,4);
    s.Insert(q,6);
    s.Insert(q,7);
    s.Insert(q,12);
    s.Preorder(q);

    Solution ob;
    Node*t= newNode(12);
    ob.Insert(t,5);
    ob.Insert(t,6);
    ob.Insert(t,9);
    ob.Preorder(t);
    Solution rr;
    if (rr.IsSameTree(q,t)){cout<< "true"<<endl;}
    else{cout<<"false"<<endl;}


    Solution a ;
    Node*qm = newNode(8);
    a.Insert(qm,4);
    a.Insert(qm,6);
    a.Insert(qm,40);
    a.Insert(qm,12);
    a.Preorder(qm);

    Solution obj;
    Node*ti= newNode(12);
    obj.Insert(ti,5);
    obj.Insert(ti,6);
    obj.Insert(ti,9);
    obj.Insert(ti,89);
    obj.Preorder(ti);
    Solution rs;
    if (rs.IsSameTree(qm,ti)){cout<< "true"<<endl;}
            else{cout<<"false"<<endl;}



    Solution x ;
    Node*po = newNode(12);
    x.Insert(po,45);
    x.Insert(po,63);
    x.Insert(po,90);
    x.Insert(po,78);
    x.Preorder(po);

    Solution obj1;
    Node*tm= newNode(12);
    obj1.Insert(tm,45);
    obj1.Insert(tm,63);
    obj1.Insert(tm,90);
    obj1.Insert(tm,78);
    obj1.Preorder(tm);
    Solution rk;
    if (rk.IsSameTree(po,tm)){cout<< "true"<<endl;}
    else{cout<<"false"<<endl;}

}


