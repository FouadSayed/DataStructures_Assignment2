
#include <iostream>
using namespace std;
int rear=-1;
int front=0;
class Queue
{
    int *arr;
    int capacity;
    int count;
public:
    Queue(int size)
    {
        arr = new int[size];
        capacity = size;
        count=0;
    }
    ~Queue()
    {
        delete[] arr;
    };

    void dequeue()
    {
        count--;
        if(front==capacity-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
    }
    void InsertQueue(int x)
    {
        count++;

        if(rear==capacity-1)
        {
            rear=0;
        }
        else
        {
            rear++;
        }
        arr[rear]=x;
    }
    int back()
    {
        return arr[rear];
    }
    int peek()
    {

        return arr[front];
    }
    int size()
    {
        return count;
    }
    int returnElement(int index)
    {
        return arr[index];
    }
    bool isEmpty()
    {
        return (size() == 0);
    }
    bool isFull()
    {
        return (size() == capacity);
    }
    void last(int x)
    {
        arr[-1]=x;
    }
};

int main()
{
    int numOfPersons,tickets;
    cout<<"Enter num of persons: ";
    cin>>numOfPersons;
    Queue myList(numOfPersons);
    for(int i=0; i<numOfPersons; i++)
    {

        cout<<"Enter how many tickets wanted by person ["<<i<<"] : ";
        cin>>tickets;
        myList.InsertQueue(tickets);

    }
    cout<<"please enter position of person k: ";
    int k;
    cin>>k;
    int pass=myList.returnElement(k);
    int temp,time=0;

    for(int i=0; i<pass,myList.returnElement(k)!=0; i++)
    {
        for(int j=0; j<numOfPersons; j++)
        {
            if(myList.peek()==0)
            {
                myList.dequeue();
                myList.InsertQueue(0);
            }
            else
            {
                temp=myList.peek();
                myList.dequeue();
                myList.InsertQueue(temp-1);
                time++;
            }

        }
    }
    cout<<"The person at position "<<k<<" has successfully bought "<<pass<<" tickets and it took "<<time<<" seconds\n";


    return 0;
}
