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
    int helper(TreeNode* root, int& max_sum) {
        if(root == NULL) return 0;

        int lh = max(0, helper(root->left, max_sum));
        int current = root->val;
        int rh = max(0, helper(root->right, max_sum));

        int sum = lh+current+rh;
        max_sum = max(max_sum, sum);
    
        return current + max(lh,rh);
    }

    int maxPathSum(TreeNode* root) {
        int max_sum = root->val;
        helper(root, max_sum);
        return max_sum;
    }
};