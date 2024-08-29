#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data1, Node* next1) {
            data = data1;
            next = next1;
        }

        Node(int data1){
            data = data1;
        }
};

void PrintLL(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head =head->next;
    }
}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

int main() {
    vector<int> arr = {12,8,5,7};

    int val = 100;

    // Inserting at end
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);

    // Insert in head
    head = insertHead(head, arr[3]);
    head = insertHead(head, val);

    PrintLL(head);
    cout<<endl;

    return 0;
}