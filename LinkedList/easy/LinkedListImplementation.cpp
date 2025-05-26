#include <iostream>

struct Node{
    int val;
    Node* next;

    Node(int val, Node* next=nullptr) : val(val), next(next) {}
};

class LinkedList{
    Node* head;
    // Add current pointer to efficeinetly keep track(tail ptr)
    Node* tail;
    
    public:
    LinkedList() : head(nullptr) {}

    Node* push_head(int val) {
        Node* temp = new Node(val);

        if(head == nullptr) {
            tail = temp;
            head = temp;
            return temp;
        }

        temp->next = head;
        head = temp;
        return temp;
    }

    Node* push_back(int val) {
        Node* temp = new Node(val);

        if(head==nullptr) {
            tail = temp;
            head = temp;
            return temp;
        }

        tail->next = temp;
        tail = temp;
        return temp;
    }

    void pop_head() {
        if(head==nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp; // delete the addreess temp is pointing to

        if(head==nullptr) tail=nullptr;
        return;
    }

    void pop_back() {
        if(tail == nullptr) return;

        Node* temp = head;

        while(temp->next != tail){
            temp = temp->next;
        }

        delete tail->next;

        tail = temp;
        tail->next = nullptr;

    }

    void display() {
        Node* temp = head;

        while(temp!=nullptr) {
            std::cout<<temp->val<<"  ";
            temp = temp->next;
        }
        std::cout<<std::endl;
    }

    void front() {
        if(head != nullptr) std::cout<<head->val<<std::endl;
    }

    void back() {
        if(tail != nullptr) std::cout<<tail->val<<std::endl;
    }
};

int main() {
    LinkedList ll;

    ll.push_head(10);
    ll.push_head(20);
    ll.push_head(30);
    ll.push_head(40);
    ll.push_back(50);
    ll.push_back(1);
    ll.display();
    ll.pop_head();
    ll.pop_back();
    ll.display();
    ll.push_back(0);
    ll.front();
    ll.back();
    ll.display();
    return 0;
}

