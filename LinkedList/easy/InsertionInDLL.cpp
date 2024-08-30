#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    // Data stored in the node
    int data;   
    // Pointer to the next node in the list (forward direction)
    Node* next;     
    // Pointer to the previous node in the list (backward direction)
    Node* back;     

    // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void print(Node* head) {
    while (head != nullptr) {
        // Print the data in the tail node
        cout << head->data << " ";  
         // Move to the next node
        head = head->next;         
    }
}


Node* insertAtTail(Node* head, int k) {
    Node* newNode = new Node(k);

    if(head == nullptr) return newNode;

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->back = temp;

    return head;
}

Node* convertArr2DLL(vector<int> arr) {
    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    // Initialize 'prev' to the head node
    Node* prev = head;            

    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the array and set its 'back' pointer to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the previous node to point to the new node
        prev->next = temp; 
         // Move 'prev' to the newly created node for the next iteration
        prev = temp;       
    }
    // Return the head of the doubly linked list
    return head;  
}


int main() {
     vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);

    cout << "Doubly Linked List Initially: " << endl;
    print(head);


    cout << endl << "Doubly Linked List After Inserting at the tail with value 10: " << endl;
     // Insert a node with value 10 at the end
    head = insertAtTail(head, 10);
    print(head);

    return 0;
}