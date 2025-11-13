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
    unordered_map<int, int> mp; // Node -> idx

    TreeNode* dfs(int left, int right, vector<int>& inorder, vector<int>& postorder, int& idx) {
        if(left > right || idx < 0) return nullptr;

        int rootVal = postorder[idx--];
        TreeNode* node = new TreeNode(rootVal);

        node->right = dfs(mp[rootVal] + 1, right, inorder, postorder, idx);
        node->left = dfs(left, mp[rootVal] - 1, inorder, postorder, idx);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++) {
            mp[inorder[i]] = i;
        }

        int idx = postorder.size() - 1;
        TreeNode* ans = dfs(0, inorder.size()-1, inorder, postorder, idx);
        return ans;
    }
};