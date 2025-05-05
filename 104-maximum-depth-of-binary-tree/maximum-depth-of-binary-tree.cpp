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
    void dfs(TreeNode* root, int &maxi, int cnt) {
        if(root == NULL) {
            return;
        }

        maxi = max(maxi, cnt);

        dfs(root->left, maxi, cnt+1);
        dfs(root->right, maxi, cnt+1);
    }

    int maxDepth(TreeNode* root) {
        int maxi = 0;
        dfs(root, maxi, 1);
        return maxi;
    }
};