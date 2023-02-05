
#include <bits/stdc++.h>
using namespace std;


class node
{
public:
    string data;
    node *left = NULL, *right = NULL;
    node(string val)
    {
        data =val;
    }
};




int convertneg(string symbol)
{
    int num = 0;
    if(symbol[0]!='-')
        for (int i=0; i<symbol.length(); i++)
            num = num*10 + (int(symbol[i])-48);
    else
    {
        for (int i=1; i<symbol.length(); i++)
            num = num*10 + (int(symbol[i])-48);
        num = num*-1;
    }

    return num;
}


int operation(node* root)
{

    if (root== nullptr)
        return 0;


    if (root->left== nullptr && root->right== nullptr)
        return convertneg(root->data);


    int dataleft = operation(root->left);


    int dataright = operation(root->right);


    if (root->data=="+")
        return dataleft+dataright;

    if (root->data=="-")
        return dataleft-dataright;

    if (root->data=="*")
        return dataleft*dataright;

    if (root->data=="/")
        return dataleft/dataright;
}

int main()
{



    node*root = new node("+");
    root->left = new node("3");
    root->right = new node("*");
    root->right->left = new node("4");
    root->right->right = new node("/");
    root->right->right->right= new node("2");
    root->right->right->left= new node("8");
    cout << operation(root) << endl;


    node* roo = new node("+");
    roo->left = new node("*");
    roo->left->left = new node("3");
    roo->left->right = new node("4");
    roo->right = new node("-");
    roo->right->left = new node("5");
    roo->right->right = new node("*");
    roo->right->right->left = new node("10");
    roo->right->right->right = new node("8");
    cout << operation(roo)<<endl;

    node* ro = new node("+");
    ro->left = new node("*");
    ro->left->left = new node("5");
    ro->left->right = new node("4");
    ro->right = new node("-");
    ro->right->left = new node("100");
    ro->right->right = new node("/");
    ro->right->right->left = new node("20");
    ro->right->right->right = new node("2");
    cout << operation(ro)<<endl;

    node* ra = new node("+");
    ro->left = new node("*");
    ro->left->left = new node("5");
    ro->left->right = new node("12");
    ro->right = new node("-");
    ro->right->left = new node("100");
    ro->right->right = new node("/");
    ro->right->right->left = new node("");
    ro->right->right->right = new node("9");
    cout << operation(ro)<<endl;

    node* rk = new node("+");
    ro->left = new node("*");
    ro->left->left = new node("5");
    ro->left->right = new node("9");
    ro->right = new node("-");
    ro->right->left = new node("40");
    ro->right->right = new node("/");
    ro->right->right->right = new node("2");
    cout << operation(ro)<<endl;



    return 0;
}


