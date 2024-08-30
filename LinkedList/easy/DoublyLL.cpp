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
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    // Create a linked list with the values from the vector
    Node* head = new Node(arr[0]);

    Node* sec = new Node(arr[1], NULL, head);
    head->next = sec;

    Node* th = new Node(arr[2], NULL, sec);
    sec->next = th;

    Node * forth = new Node(arr[3], NULL, th);
    th->next = forth;

    printDLL(head);
    cout<<endl;
    revPrintDLL(forth);

    return 0;
}

