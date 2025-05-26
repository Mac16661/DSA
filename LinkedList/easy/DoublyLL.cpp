#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;

        Node(int data1, Node* next1, Node* back1) {
            data = data1;
            next = next1;
            back = back1;
        }

        Node(int data1) {
            data = data1;
            next = nullptr;
            back = nullptr;
        }
};

void printDLL(Node* head){
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void revPrintDLL(Node* tail) {
    Node* temp = tail;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp= temp->back;
    }
    cout<<endl;
}

Node* insertIntoHead(Node*& head, int val) {
    if(head==nullptr){
        head = new Node(val);
        return head;
    }

    Node* temp = new Node(val);
    head->back = temp;
    temp->next = head;
    head = temp;
    return head;
}

Node* insertIntoTail(Node*& tail, int val) {
    Node* newNode = new Node(val);
    if(tail==nullptr){
        tail = newNode;
        return tail;
    }

    tail->next = newNode;
    newNode->back = tail;
    tail = newNode;
    return tail;
}

Node* deleteTail(Node*& tail) {
    Node* temp = tail;
    tail = tail->back;
    tail->next = nullptr;
    delete temp;

    return tail;
}

// we are changing the actual pointer value here
void searchDel(Node* head, int val) {
    Node* temp = head;

    // Search for the node with given value
    while (temp != nullptr && temp->data != val) {
        temp = temp->next;
    }

    // If not found, do nothing
    if (temp == nullptr) return;

    // If it's the head node
    if (temp == head) {
        head = head->next;
        if (head != nullptr) {
            head->back = nullptr;
        }
    }
    else {
        if (temp->back) temp->back->next = temp->next;
        if (temp->next) temp->next->back = temp->back;
    }

    delete temp;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    // Create a linked list with the values from the vector
    // Node* head = new Node(arr[0]);

    // Node* sec = new Node(arr[1], NULL, head);
    // head->next = sec;

    // Node* th = new Node(arr[2], NULL, sec);
    // sec->next = th;

    // Node * forth = new Node(arr[3], NULL, th);
    // th->next = forth;

    Node* head = nullptr;
    Node* tail = nullptr;
    tail = insertIntoHead(head, 1);
    insertIntoHead(head, 2);
    insertIntoHead(head, 3);
    tail = insertIntoTail(tail, 4);
    tail = insertIntoTail(tail, 5);

    printDLL(head);
    searchDel(head, 1);
    // deleteTail(tail);deleteTail(tail);
    cout<<"After delet: "<<endl;
    printDLL(head);
    cout<<endl<<endl;
    revPrintDLL(tail);

    return 0;
}

