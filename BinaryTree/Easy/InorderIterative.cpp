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

void Inorder(Node* root) {
    if(root == NULL) return;
    stack<Node*> st;
    Node* node = root;
    
    while(true) {
        if(node != NULL) {
            st.push(node);
            node = node->left;
        }else {
            //I have to print TOS & move to right children
            if(st.empty()) break;
            node = st.top();
            st.pop();
            cout<< node->val;
            node = node->right;
        }
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

    Inorder(root);
    return 0;
}