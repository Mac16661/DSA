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
    int findMax(vector<int>& nums) {
        int maxInd = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[maxInd] < nums[i]) maxInd = i;
        }

        return maxInd;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;

        int maxInd = findMax(nums);
        TreeNode* root = new TreeNode(nums[maxInd]);

        vector<int> left(nums.begin(), nums.begin() + maxInd);
        vector<int> right(nums.begin() + maxInd + 1, nums.end());

        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);

        return root;
    }
};