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
    // doing preorder
    void helper(TreeNode* root, int& sum, char pos) {
        if(root == nullptr) return;

        if(root->left == nullptr and root->right ==nullptr and pos =='l') sum+= root->val;

        helper(root->left, sum, 'l');
        helper(root->right, sum, 'r');
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, sum, 'r');
        return sum;
    }
};