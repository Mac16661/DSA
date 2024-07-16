#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left = NULL;
    Node* right = NULL;

    Node(int data) {
        val = data;
    }
};

void preOrder(Node* root){
    if(root == nullptr) {
            return;
    }
    stack<Node*> st;
    st.push(root);

    while(!st.empty()) {
        Node* temp = st.top();
        st.pop();

        cout<<temp->val;

        //Cheching if they have any childrens
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->left = new Node(4);
    root->right->right = new Node(5);

    root->left->left = new Node(6);
    root->left->right = new Node(7);

    preOrder(root);

    return 0;
}