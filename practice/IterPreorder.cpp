#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void printVector(const vector<int>& vec) {
    // Iterate through the vector
    // and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

vector<int> postOrder(Node* root) {
    vector<int> ans;
    stack<Node*> s1, s2;
    // stack<Node*> s2;

    s1.push(root);

    while(!s1.empty()) {
        Node* curr = s1.top();
        s1.pop();

        s2.push(curr);

        if(curr->left) {
            s1.push(curr->left);
        }

        if(curr->right) {
            s1.push(curr->right);
        }
    }

    while(!s2.empty()){
        ans.push_back(s2.top()->data);
        s2.pop();
    }

    return ans;
}

// TODO: Optimal solution -> using only one stack


// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting postorder traversal
    vector<int> result = postOrder(root);

    // Printing the postorder
    // traversal result
    cout << "Postorder traversal: ";
    printVector(result);

    return 0;
}