// Tree+Hashing
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left, *right;
};

Node* newNode(int key){
    Node* node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void getVerticalOrder(Node* root, int hist, map<int,vector<int>>& mp){

    if(root == NULL) return;

    mp[hist].push_back(root->key);
    

    getVerticalOrder(root->left, hist-1, mp);
    getVerticalOrder(root->right, hist+1, mp);
    
}

int main() {
    Node *root = newNode(10);
    root->left = newNode(7);
    root->right = newNode(4);
    root->left->left = newNode(3);
    root->left->right = newNode(11);
    root->right->left = newNode(14);
    root->right->right = newNode(6);

    map<int, vector<int>> mp;

    getVerticalOrder(root, 0, mp);


    for(auto i : mp){
        for(auto it : i.second){
            cout<< i.first<< " : "<<it<<" ";
        }
        cout<<endl;
    }



    return 0;
}