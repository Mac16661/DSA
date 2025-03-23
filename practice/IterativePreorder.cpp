#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
};

void CreateTree(Node* &root, vector<int> arr) {
    queue<Node*> q;
    int ind = 0;
    root = new Node(arr[ind++]);
    q.push(root);

    while(!q.empty() && ind < arr.size()) {
        Node* curr = q.front();
        q.pop();

        if(ind < arr.size()) {
            Node* l = new Node(arr[ind]);
            curr->left = l;
            q.push(l);
            ind++;
        }

        if(ind < arr.size()) {
            Node* r  = new Node(arr[ind]);
            curr->right = r;
            q.push(r);
            ind++;
        }

    }
}

void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout<<curr->val<<" ";

        if(curr->left) {
            q.push(curr->left);
        }

        if(curr->right) {
            q.push(curr->right);
        }
    }
}

void iterPre(Node* root) {
    stack<Node*> st;
    st.push(root);

    while(!st.empty()) {
        Node* curr = st.top();
        st.pop();

        cout<<curr->val<<" ";

        if(curr->right) {
            st.push(curr->right);
        }

        if(curr->left) {
            st.push(curr->left);
        }
    }

}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    Node* root;

    CreateTree(root, arr);

    iterPre(root);

    return 0;
}