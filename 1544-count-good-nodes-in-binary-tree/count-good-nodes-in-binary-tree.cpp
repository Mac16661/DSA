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
    int helper(TreeNode* root, int maxi) {
        if(root == nullptr) return 0;
        int cnt = 0;

        if(root->val >= maxi) {
            maxi = root->val;
            cnt++;
        }

        int left = helper(root->left, maxi);
        int right = helper(root->right, maxi);

        return cnt+left+right;
    }

    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }
};