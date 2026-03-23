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
    int widthOfBinaryTree(TreeNode* root) {
        // In level order traveral what if we just pass along the null
        if (!root) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        long long maxWidth = 0;

        while (!q.empty()) {
            int size = q.size(); // number of nodes in current level
            long long first = q.front().second;
            long long last = q.back().second;
            maxWidth = max(maxWidth, last - first + 1);

            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                q.pop();
                
                // Normalize index to avoid overflow
                long long normIdx = idx - first;
                
                if (node->left)  q.push({node->left,  2 * normIdx});
                if (node->right) q.push({node->right, 2 * normIdx + 1});
            }
        }
        return (int)maxWidth;
    }
};