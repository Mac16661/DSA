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
        if(root == nullptr) return tree;

        helper(root, tree);
        return tree;
    }
};