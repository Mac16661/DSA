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
    unordered_map<string, int> mp; // Hashmap for subtree
    vector<TreeNode*> res;

    string helper(TreeNode* node) {
        if (node == nullptr) return "#"; 

        string s = to_string(node->val) + "," + helper(node->left) + "," + helper(node->right);

        mp[s]++;
        if (mp[s] == 2) {
            res.push_back(node);
        }

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return res;
    }
};