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

void printLL(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head =head->next;
    }
}

int LLLength(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }

    return count;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    // Create a linked list with the values from the vector
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    // Call the deleteTail function to delete the last node
    // head = deleteTail(head);
    // Print the linked list after deletion
    cout<<LLLength(head)<<endl;
    printLL(head);
    return 0;
}