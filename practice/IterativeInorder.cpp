#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

vector<int> inOrder(Node* root){
    vector<int> ans;
    stack<Node*> st;

    while(true) {
        if(root != NULL) {
            st.push(root);
            root = root->left;
        }else{
            if(st.empty()) break;
            root = st.top();
            st.pop();

            ans.push_back(root->val);
            root=root->right;
        }
    }
    
    return ans;

}

int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting inorder traversal
    vector<int> result = inOrder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    // Output each value in the
    // inorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}