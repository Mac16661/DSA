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

// TODO: It is using 2 stack to implement it 
void postOrder(Node* root) {
    if(root == NULL) return;

    stack<Node*> st1,st2;
    Node* node = root;
    st1.push(root);

    while(!st1.empty()) {
        root = st1.top();
        st1.pop();

        // Pushing root into the stack 2
        st2.push(root);

        //If root have children push it into stack1 and in next iter push it into stack2
        if(root->left) st1.push(root->left);
        if(root->right) st1.push(root->right);
    }

    //Printing st2 which will have final values one by one
    while(!st2.empty()) {
        cout<<st2.top()->val<<" ";
        st2.pop();
    }

}

// TODO: Optimal Using only 1 Stack
void OptimalPostOrder1(Node* root) {
    if(root == nullptr) return;
    stack<Node*> st;
    Node* curr = root;
    Node* lastVisited = nullptr;

    while(!st.empty() || curr != nullptr) {
        if(curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        } else {
            Node* peekNode = st.top();
            if(peekNode->right != nullptr && lastVisited != peekNode->right) {
                curr = peekNode->right;
            } else {
                cout << peekNode->val << " ";
                lastVisited = st.top();
                st.pop();
            }
        }
    }
    cout << endl;
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->left = new Node(4);
    root->right->right = new Node(5);

    root->left->left = new Node(6);
    root->left->right = new Node(7);

    OptimalPostOrder1(root);
    return 0;
}