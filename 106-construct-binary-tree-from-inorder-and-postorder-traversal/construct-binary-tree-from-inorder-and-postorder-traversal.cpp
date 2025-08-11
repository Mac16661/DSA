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
    unordered_map<int,int> mpp; // val -> index in inorder
    int post_idx = 0;

    TreeNode* dfs(vector<int>& postorder, vector<int>& inorder, int l, int r) {
        if (l > r) return nullptr;

        int root_val = postorder[post_idx];
        TreeNode* root = new TreeNode(root_val);
        int mid = mpp[root_val];
        post_idx--;

        // build right before left
        root->right = dfs(postorder, inorder, mid + 1, r);
        root->left = dfs(postorder, inorder, l, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post_idx = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        return dfs(postorder, inorder, 0, inorder.size() - 1);
    }
};
