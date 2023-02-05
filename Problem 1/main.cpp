#include <iostream>
#include <string>
using namespace std;
template <class type>
class stack{
private:
    struct node{
        type data;
        node *next;
    };
    node *Top;
    int size;
public:
    stack(){
        Top = NULL;
        size=0;
    }
    void push(type val){
        node *new_node=new node;
        new_node->data=val;
        new_node->next=Top;
        Top=new_node;
        size++;
    }
    void pop(){
        if(this->is_empty()){
            cout<<"stack is already empty."<<endl;
        }
        else{
            node *first=Top;
            Top=first->next;
            delete(first);
            size--;
        }
    }
    type top(){
        type val=Top->data;
        return val;
    }
    void display(){
        if(Top == NULL){
            cout<<"stack is empty."<<endl;
        }
        else{
            node *current=Top;
            while(current != NULL){
                type val=current->data;
                cout<<val;
                current=current->next;
            }
        }
    }
    bool is_empty(){
        if(Top == NULL || size==0)
            return true;
        else
            return false;
    }
    int get_size(){
        return size;
    }
};
int main() {
    string f_name;
    cin>>f_name;
    stack <char> stk;
    int num_dots=0 , x=0;
    for (int i = 0; i < f_name.size(); ++i) {
        if(f_name[i] == '.') {
            num_dots++;
        }
        else if(f_name[i] != '.'){
            x=num_dots;
            num_dots=0;
            if(x == 0){
                if(f_name[i] == '/'){
                    if(!stk.is_empty()) {
                        if (stk.top() == '/') {
                            continue;
                        } else {
                            stk.push(f_name[i]);
                        }
                    }
                    else
                        stk.push(f_name[i]);
                }
                else {
                    stk.push(f_name[i]);
                }
            }
            else if(x == 1)
                continue;
            else if(x == 2){
                i--;
                stk.pop();
                if(!stk.is_empty()) {
                    while (stk.top() != '/')
                        stk.pop();
                    if (i == f_name.size() - 1)
                        stk.pop();
                }
                else
                    continue;
            }
            else if(x >= 3){
                while(x>0) {
                    stk.push('.');
                    x--;
                }
            }
        }
    }
    int m=stk.get_size();
    if(stk.top() == '/' && m>1)
        stk.pop();
    stack<char>res;
    m=stk.get_size();
    for (int i = 0; i < m ; ++i) {
        res.push(stk.top());
        stk.pop();
    }
    res.display();
}