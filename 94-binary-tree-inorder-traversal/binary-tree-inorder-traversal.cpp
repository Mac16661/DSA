/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, vector<int>& tree) {
        if(root == nullptr) return;

        // left
        helper(root->left, tree);

        // root
        tree.push_back(root->val);

        // right
        helper(root->right, tree);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> tree;
        // if(root == nullptr) return tree;

        // helper(root, tree);
        // return tree;

        // iterative preorder traversal
        // if(root == nullptr) return tree;
        // stack<TreeNode*> st;
        // st.push(root);

        // while(!st.empty) {
        //     TreeNode* temp = st.top();
        //     st.pop();

        //     tree.push_back(temp->val);

        //     if(temp->right) st.push(temp->right);
        //     if(temp->left) st.push(temp->left);
        // }
        // return tree;

        // iterative inorder
        if(root == nullptr) return tree;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr || !st.empty()) {
            // push all possible left nodes 
            while(curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            tree.push_back(curr->val);

            // move to right node
            curr = curr->right;
        }

        return tree;
    }

    
};