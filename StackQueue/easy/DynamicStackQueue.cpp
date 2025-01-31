#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
    
        Node(int val) {
            this->val = val;
            this->next = nullptr;
        } 
};

// IMPLEMENTING DYNAMIC STACK [LINKEDKIST]
class DynamicStack{
    private:
        Node* top = nullptr;
        int size = 0;

    public:
        void push(int x) {
            Node* head = new Node(x);
            head->next = top;
            top = head;
            size++;
        }

        int pop() {
            Node* temp = top;
            top = top->next;
            delete temp;
            size--;
            return top->val;
        }

        int topS() {
            return top->val;
        }

        int Ssize() {
            return size;
        }

};

class DynamicQueue{
    private:
        Node* start = nullptr;
        Node* end = nullptr;
        int size = 0;

    public:
        void push(int x) {
            if(start == nullptr){
                end = new Node(x);
                start = end;
                size++;
                return;
            }

            end->next = new Node(x);
            end = end->next;
            size++;
        } 

        int pop(){
            if(start == nullptr) {
                return -1;
            }
            Node* temp = start;
            start=start->next;
            delete temp;
            size--;

            if(start == nullptr) {
                end = nullptr;
            }

            return start->val;
        }

        int front() {
            if(start != nullptr){
                return start->val;
            }
            return -1;
        }

        int Qsize(){
            return size;
        }

};

int main() {
    DynamicStack ds;

    ds.push(10);
    ds.push(20);
    ds.push(30);

    cout<<ds.topS()<<endl;
    cout<<ds.Ssize()<<endl;
    cout<<ds.pop()<<endl;
    cout<<ds.pop()<<endl;

    cout<<"DYNAMIC QUEUE---------------\n";
    DynamicQueue dq;

    dq.push(10);
    dq.push(20);
    dq.push(30);

    cout<<dq.front()<<endl;
    cout<<dq.pop()<<endl;
    cout<<dq.pop()<<endl;
    cout<<dq.Qsize()<<endl;

    return 0;
}