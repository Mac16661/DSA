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

class Solution{
public:
    void LeftView(Node* root, vector<int> &res) {
        stack<int> st;
        while(root) {
            st.push(root->data);
            root= root->left;
        }

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
    }

    void RightView(Node* root, vector<int> &res) {
        while(root){
            res.push_back(root->data);
            root = root->right;
        }
    }

    vector<int> topView(Node* root){
        vector<int> res;
        if(root == NULL) return res;

        //topLeft
        LeftView(root, res);

        //topRight
        RightView(root->right, res);

        return res;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    // Get the top view traversal
    vector<int> topView =
                    solution.topView(root);

    // Print the result
    cout << "Top View Traversal: "<< endl;
    for(auto node: topView){
        cout << node << " ";
    }

    return 0;
}