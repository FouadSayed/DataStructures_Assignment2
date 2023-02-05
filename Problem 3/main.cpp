#include<iostream>
using namespace std;
class NewNode{
public:
    int val;
    NewNode * next;
    NewNode() {
        val = 0;
        next = NULL;
    }
};
class Queue {
public:
    NewNode*first;
    NewNode*last;
    int siz;
    Queue()
    {
        first= last= NULL;
        siz=0;
    }

    bool empty()
    {
        if(first == NULL && last == NULL)
            return true;
        else
            return false;
    }
    int dequeue()
    {
        int Value=-1;
        if(empty()){
            cout<<" queue is empty"<<endl;
        }
        else if(first == last)
        {
            delete first;
            first= last=NULL;
        }
        else
        {
            NewNode*delptr=first;
            first=first->next;
            Value=delptr->val;
            delete delptr;
        }
        siz--;
        return Value;
    }
    void enqueue(int item)
    {
        NewNode*node= new NewNode;
        node->val=item;
        if(empty())
            first= last=node;
        else
        {
            last->next=node;
            last=node;
        }
        siz++;
    }

    int getFirst()
    {
        return first->val;
    }
    int getsize(){
        return siz;
    }
};


class Stack
{
    Queue que;
public:
    int top()
    {
        if (que.empty())
        {
            return -1;
        }
        else
        {
            return que.getFirst();
        }
    }
    void pop()
    {
        if (que.empty())
            cout << "queue is empty"<<endl;
        else

            cout << "pop : " << que.dequeue() << endl;
    }
    void push(int value)
    {
        int size=que.getsize();
        que.enqueue(value);
        for (int i = 0; i <size ; ++i)
        {
            que.enqueue(que.getFirst());
            que.dequeue();
        }
    }

};

int main()
{
    Stack n;
    n.push(7);
    n.push(5);
    n.push(50);
    n.push(9);
    cout<<n.top()<<endl;
    n.pop();
    cout<<n.top()<<endl;
    n.push(1);
    n.pop();
    cout << n.top() << endl;
    return 0;
}

