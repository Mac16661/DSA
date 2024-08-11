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
    int helper(TreeNode* root, int depth) {
        if(root == NULL) return depth;

        int left = helper(root->left, depth+1);
        int right = helper(root->right, depth+1);

        return max(left, right);
    }

    int maxDepth(TreeNode* root) {
        return helper(root, 0);
    }
};