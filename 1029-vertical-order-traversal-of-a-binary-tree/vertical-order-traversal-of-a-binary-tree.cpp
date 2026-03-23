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
    void preorder(TreeNode* root, int row, int col, map<int, vector<pair<int,int>>>& mpp) {
        if (!root) return;

        mpp[col].push_back({row, root->val});
        preorder(root->left, row + 1, col - 1, mpp);  // left child
        preorder(root->right, row + 1, col + 1, mpp); // right child
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        map<int, vector<pair<int,int>>> mpp; // col -> list of (row, val)
        preorder(root, 0, 0, mpp);

        for (auto& [col, nodes] : mpp) {
            // Sort by row first, then value
            sort(nodes.begin(), nodes.end(), [](auto &a, auto &b) {
                if (a.first == b.first) return a.second < b.second; // same row → smaller value first
                return a.first < b.first; // smaller row first
            });

            vector<int> colVals;
            for (auto &p : nodes) colVals.push_back(p.second);
            ans.push_back(colVals);
        }
        return ans;
    }
};
