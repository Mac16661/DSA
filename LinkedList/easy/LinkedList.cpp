#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }

        Node(int data1){
            data = data1;
        }
};

int main() {
    Node* x = new Node(1,nullptr);
    // cout<<x;
    // cout<<endl;
    // cout<<&x;
    Node* y = new Node(2, x);
    

    cout<<y->data<<endl;
    cout<<y->next->data<<endl;
    cout<<x->data<<endl;
    return 0;
}