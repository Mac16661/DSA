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
    string tree2str(TreeNode* root) {
        if (!root) return "";
        
        // Base: leaf node
        if (!root->left && !root->right)
            return to_string(root->val);
        
        // If right child exists, include both
        if (root->right)
            return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
        
        // If only left child exists
        return to_string(root->val) + "(" + tree2str(root->left) + ")";
    }
};