#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left= right = NULL;
    }
};

void CreateTree(vector<int> &arr, Node* &root) {
    int ind = 0;
    root = new Node(arr[ind++]);
    queue<Node*> q;
    q.push(root);

    while(ind < arr.size() && !q.empty()) {
        Node* current = q.front();
        q.pop();

        if(ind < arr.size()) {
            Node* leftChild = new Node(arr[ind]);
            current->left = leftChild;
            q.push(leftChild);
            ind++;
        }

        if(ind < arr.size()) {
            Node* rightChild = new Node(arr[ind]);
            current->right = rightChild;
            q.push(rightChild);
            ind++;
        }
    }
}

void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
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

vector<vector<int>> levelOrderL(Node* root) {
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        vector<int> level;
        int size = q.size();

        for(int i=0; i<size; i++) {
            Node* curr = q.front();
            q.pop();

            level.push_back(curr->val);

            if(curr->left) {
                q.push(curr->left);
            }

            if(curr->right) {
                q.push(curr->right);
            }
        }

        ans.push_back(level);

    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    Node* root;

    CreateTree(arr, root);

    levelOrder(root);

    return 0;
}