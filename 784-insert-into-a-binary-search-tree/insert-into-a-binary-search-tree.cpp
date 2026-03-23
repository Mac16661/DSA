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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) {
            return new TreeNode(val);
        }

        // if smaller than root then left
        if(val < root->val) {
            root->left = insertIntoBST(root->left, val);
            return root;
        }
        else if(val > root->val) { // if bigger than root then right subtree
            root->right = insertIntoBST(root->right, val);
            return root;
        }

        return root;
    }
};