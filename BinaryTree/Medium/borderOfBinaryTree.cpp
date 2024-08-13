// TODO: Boundary of a binary tree
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
    private:

    bool isLeaf(Node* root) {
        return !root->leaf && !root->right;
    }

    void addLeftBoundary(Node* root, vector<int> &res){
        Node* curr = root->left;
        while(curr) {
            if(!isLeaf(curr)) {
                res.push_back(curr->data);
            }

            // if left exists then go left else right till second last row
            if(curr->left){
                curr = curr->left;
            }else{
                curr = curr->right;
            }

        }
    }

    void addRightBoundary(Node* root, vector<int> &res){
        Node* curr = root->right;
        vector<int> temp;
        while (curr) {
            // If the current node is not a leaf,
            // add its value to a temporary vector
            if (!isLeaf(curr)) {
                temp.push_back(curr->data);
            }
            // Move to the right child if it exists,
            // otherwise move to the left child
            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        // Reverse and add the values from
        // the temporary vector to the result
        for (int i = temp.size() - 1; i >= 0; --i) {
            res.push_back(temp[i]);
        }
    }

    void addLeaves(Node* root, vector<int> &res) {
        if(isLeaf(root)) {
            res.push_back(root->data);
            return;
        }

        if(root->left) addLeaves(root->left, res);

        if(root->right) addLeaves(root->right, res);

    }

    public:
    vector<int> printBoundary(Node* root) {
        vector<int> res;
        if(!root) return res; // if null

        // If root is not leaf
        if(!isLeaf(root)) {
            res.push_back(root->data);
        }

        addLeftBoundary(root, res);
        addLeaves(root,res);
        addRightBoundary(root,res);
    }
}