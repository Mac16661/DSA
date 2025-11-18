class Solution {
    int globalMax = INT_MIN;

    int helper(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));

        globalMax = max(globalMax, root->val + left + right);

        return root->val + max(left, right); // can go to only one path
    }
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return globalMax;
    }
};