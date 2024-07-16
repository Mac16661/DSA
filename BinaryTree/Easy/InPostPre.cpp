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

// TODO: Pre, Inorder and post order in one go
void allIn(Node* root){
    if(root == nullptr) return;
    stack<pair<Node*, int>> st;
    st.push({root,1});
    vector<int> pre, post, in;

    while(!st.empty()) {
        auto it = st.top();
        st.pop();

        if(it.second == 1) {
            pre.push_back(it.first->val);
            it.second++;

            st.push(it);
            if(it.first->left) {
                st.push({it.first->left, 1});
            }
        }
        else if(it.second == 2) {
            in.push_back(it.first->val);
            it.second++;

            st.push(it);
            if(it.first->right) {
                st.push({it.first->right, 1});
            }

        }
        else{
            post.push_back(it.first->val);
        }
    }

    for(auto i: pre) cout<<i<<" ";
    cout<<endl;

    for(auto i: in) cout<<i<<" ";
    cout<<endl;

    for(auto i: post) cout<<i<<" ";
    cout<<endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->left = new Node(4);
    root->right->right = new Node(5);

    root->left->left = new Node(6);
    root->left->right = new Node(7);

    allIn(root);
    return 0;
}