#include <iostream>
#include <vector>
using namespace std;
class BSTNODE
{
public:
    int Data;
    BSTNODE* Left;
    BSTNODE* Right;
    BSTNODE()
    {
        Data,Left,Right=NULL;
    };
    BSTNODE(int data)
    {
        Data=data;
        Left=Right=NULL;
    }
};

class BSTFCI
{
public:
    BSTNODE* root;
    BSTFCI(int NodeData)
    {
        BSTNODE* n = new BSTNODE(NodeData);
        root = n;
    }
    int height(BSTNODE* node)
    {
        if (node == NULL)
            return 0;
        else
        {
            return 1 + max(height(node->Left),
                           height(node->Right));
        }
    }
    int max(int a, int b)
    {
        if (a>=b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    int min(int a,int b)
    {
        if (a>=b)
        {
            return b;
        }
        else
        {
            return a;
        }

    }
    bool isBalanced(BSTNODE* root)
    {
        int leftheight;
        int rightheight;
        if (root == NULL)
            return true;
        leftheight= height(root->Left);
        rightheight = height(root->Right);
        if (abs(leftheight- rightheight) <= 1 && isBalanced(root->Left) && isBalanced(root->Right))
            return true;
        else
        {
            return false;
        }
    }


    bool CheckSameTree(BSTNODE  * node1, BSTNODE  *node2)
    {
        if (node1 == NULL && node2 == NULL)
            return true;
        else if (node1 == NULL || node2 == NULL)
            return false;
        else
            return (node1->Data == node2->Data && CheckSameTree(node1->Left, node2->Left) && CheckSameTree(node1->Right, node2->Right) );
    }
    bool Subtree(BSTNODE  *node1, BSTNODE  *node2)
    {
        if (node1 == NULL)
            return false;
        if (CheckSameTree(node1, node2)||node2==NULL)
            return true;
        return Subtree(node1->Left, node2) || Subtree(node1->Right, node2);
    }

    bool Subtree(BSTFCI  *T, BSTFCI  *S)
    {
        return Subtree(T->root,S->root);
    }

    void printRange(BSTNODE *node, int num, int num2)
    {

        if(node!=NULL)
        {
            this->printRange(node->Left, num, num2);

            if (node->Data >= min(num,num2) && node->Data <= max(num,num2))
                cout<<(node->Data)<<" ";
            this->printRange(node->Right, num, num2);

        }

    }
    void printRange(int firstNum,int secondNum)
    {
        cout<<"[";
        printRange(this->root, firstNum,secondNum);
        cout<<"]";
    }

};






// Test main program
int main()
{
    cout<<"Test Case 1:\n";

    cout<<"Tree 1 = ";
    BSTFCI* Tree1 = new BSTFCI(6);
    Tree1->root->Left= new BSTNODE(3);
    Tree1->root->Right= new BSTNODE(7);
    Tree1->root->Right->Left= new BSTNODE(2);
    Tree1->root->Left->Left= new BSTNODE(1);
    Tree1->root->Left->Left->Left= new BSTNODE(0);
    Tree1->root->Left->Right= new BSTNODE(4);
    Tree1->printRange(0,9);



    cout<<"\nTree 2 = ";
    BSTFCI* Tree2  = new BSTFCI(3);
    Tree2->root->Left= new BSTNODE(1);
    Tree2->root->Right= new BSTNODE(4);
    Tree2->root->Left->Left= new BSTNODE(0);
    Tree2->printRange(0,9);

    if (Tree1->isBalanced(Tree1->root))
        cout << "\nTree 1 is balanced"<<endl;
    else
        cout << "\nTree 1 is not balanced" <<endl;
    if(Tree1->Subtree(Tree1,Tree2))
        cout<<"Tree 2 Is SubTree from Tree 1\n";
    else
        cout<<"Tree 2 Is not SubTree from Tree 1\n";
    cout << "In Tree 1, Nodes Between Range [3,7] = " ;
    Tree1->printRange(3,7);


    cout<<"\n----------------------------------------------------\n";

    cout<<"Test Case 2:\n";

    cout<<"Tree 3 = ";
    BSTFCI* Tree3 = new BSTFCI(10);
    Tree3->root->Left= new BSTNODE(7);
    Tree3->root->Right= new BSTNODE(12);
    Tree3->root->Right->Left= new BSTNODE(11);
    Tree3->root->Right->Right= new BSTNODE(15);
    Tree3->root->Right->Right->Right= new BSTNODE(16);
    Tree3->root->Left->Left= new BSTNODE(6);
    Tree3->root->Left->Left->Left= new BSTNODE(4);
    Tree3->root->Left->Right= new BSTNODE(9);
    Tree3->root->Left->Right->Left= new BSTNODE(8);
    Tree3->printRange(0,20);

    cout<<"\nTree 4 = ";
    BSTFCI* Tree4  = new BSTFCI(7);
    Tree4->root->Left= new BSTNODE(6);
    Tree4->root->Right= new BSTNODE(9);
    Tree4->root->Right->Left= new BSTNODE(8);
    Tree4->root->Left->Left= new BSTNODE(4);
    Tree4->printRange(0,15);
    if (Tree4->isBalanced(Tree4->root))
        cout << "\nTree 4 is balanced"<<endl;
    else
        cout << "\nTree 4 is not balanced" <<endl;
    if(Tree4->Subtree(Tree3,Tree4))
        cout<<"Tree 4 Is SubTree from Tree 3\n";
    else
        cout<<"Tree 4 Is not SubTree from Tree 3\n";
    cout << "In Tree 3, Nodes Between Range [4,10] = " ;
    Tree3->printRange(4,10);

    cout<<"\n----------------------------------------------------\n";
    cout<<"Test Case 3:\n";

    cout<<"Tree 5 = ";
    BSTFCI* Tree5 = new BSTFCI(20);
    Tree5->root->Left= new BSTNODE(19);
    Tree5->root->Right= new BSTNODE(25);
    Tree5->root->Right->Right= new BSTNODE(30);
    Tree5->root->Right->Right->Right= new BSTNODE(32);
    Tree5->root->Right->Left= new BSTNODE(22);
    Tree5->root->Right->Left->Right= new BSTNODE(23);
    Tree5->root->Right->Left->Right->Right= new BSTNODE(24);

    Tree5->printRange(0,40);

    cout<<"\nTree 6 = ";
    BSTFCI* Tree6  = new BSTFCI(22);
    Tree6->root->Right= new BSTNODE(23);
    Tree6->root->Right->Right= new BSTNODE(24);
    Tree6->printRange(20,30);

    if (Tree5->isBalanced(Tree5->root))
        cout << "\nTree 5 is balanced"<<endl;
    else
        cout << "\nTree 5 is not balanced" <<endl;
    if(Tree5->Subtree(Tree5,Tree6))
        cout<<"Tree 6 Is SubTree from Tree 5\n";
    else
        cout<<"Tree 6 Is not SubTree from Tree 5\n";
    cout << "In Tree 5, Nodes Between Range [22,30] = " ;
    Tree5->printRange(22,30);
    cout<<"\n----------------------------------------------------\n";
    cout<<"Test Case 4:\n";

    cout<<"Tree 7 = ";
    BSTFCI* Tree7 = new BSTFCI(42);
    Tree7->root->Left= new BSTNODE(29);
    Tree7->root->Left->Left= new BSTNODE(27);
    Tree7->root->Left->Left->Left= new BSTNODE(25);
    Tree7->root->Left->Left->Right= new BSTNODE(28);
    Tree7->root->Left->Left->Left->Right= new BSTNODE(26);
    Tree7->root->Left->Right= new BSTNODE(31);
    Tree7->root->Left->Right->Left= new BSTNODE(30);

    Tree7->root->Right= new BSTNODE(47);
    Tree7->root->Right->Right= new BSTNODE(50);

    Tree7->root->Right->Right->Left= new BSTNODE(48);
    Tree7->root->Right->Left= new BSTNODE(45);
    Tree7->root->Right->Left->Left= new BSTNODE(43);


    Tree7->printRange(0,55);

    cout<<"\nTree 8 = ";
    BSTFCI* Tree8  = new BSTFCI(29);
    Tree8->root->Left= new BSTNODE(27);
    Tree8->root->Right= new BSTNODE(31);
    Tree8->root->Left->Left= new BSTNODE(25);
    Tree8->root->Left->Right= new BSTNODE(35);
    Tree8->printRange(0,40);
    if (Tree7->isBalanced(Tree7->root))
        cout << "\nTree 7 is balanced"<<endl;
    else
        cout << "\nTree 7 is not balanced" <<endl;
    if(Tree7->Subtree(Tree7,Tree8))
        cout<<"Tree 8 Is SubTree from Tree 8\n";
    else
        cout<<"Tree 8 Is not SubTree from Tree 7\n";
    cout << "In Tree 7, Nodes Between Range [30,50] = " ;
    Tree7->printRange(30,50);
    cout<<"\n----------------------------------------------------\n";
    cout<<"Test Case 5:\n";

    cout<<"Tree 9 = ";
    BSTFCI* Tree9 = new BSTFCI(100);
    Tree9->root->Left= new BSTNODE(95);
    Tree9->root->Left->Left= new BSTNODE(92);
    Tree9->root->Left->Right= new BSTNODE(96);
    Tree9->root->Right= new BSTNODE(110);
    Tree9->root->Right->Right= new BSTNODE(115);
    Tree9->root->Right->Right->Left= new BSTNODE(113);
    Tree9->root->Right->Right->Left->Right= new BSTNODE(114);
    Tree9->root->Right->Left= new BSTNODE(107);
    Tree9->root->Right->Left->Left= new BSTNODE(106);
    Tree9->root->Right->Left->Right= new BSTNODE(108);
    Tree9->root->Right->Left->Right->Right= new BSTNODE(109);
    Tree9->root->Right->Left->Left->Left= new BSTNODE(102);
    Tree9->printRange(90,120);


    cout<<"\nTree 10 = ";
    BSTFCI* Tree10  = new BSTFCI(107);
    Tree10->root->Left= new BSTNODE(106);
    Tree10->root->Right= new BSTNODE(119);
    Tree10->root->Right->Right= new BSTNODE(109);
    Tree10->root->Left->Left= new BSTNODE(102);

    Tree10->printRange(100,120);
    if (Tree9->isBalanced(Tree9->root))
        cout << "\nTree 9 is balanced"<<endl;
    else
        cout << "\nTree 9 is not balanced" <<endl;
    if(Tree9->Subtree(Tree9,Tree10))
        cout<<"Tree 10 Is SubTree from Tree 9\n";
    else
        cout<<"Tree 10 Is not SubTree from Tree 9\n";
    cout << "In Tree 9, Nodes Between Range [100,110] = " ;
    Tree9->printRange(100,110);

    cout<<"\n----------------------------------------------------\n\n\n\n";
    return 0;
}
