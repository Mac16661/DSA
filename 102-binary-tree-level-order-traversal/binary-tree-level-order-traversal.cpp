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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> tree;
        if(root == nullptr) return tree;

        queue<TreeNode*> q;
        q.push(root);
        int l = 0;

        // bfs traversal
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;

            // loop
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }

            tree.push_back(level);
            l++; // level
        }

        return tree;
    }
};