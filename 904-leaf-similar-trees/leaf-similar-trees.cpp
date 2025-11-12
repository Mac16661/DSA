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
    // Do preorder traversal and store the leaf in leafs arr
    void helper(TreeNode* root, vector<int>& leafs) {
        if(root == nullptr) return;

        //check if current node is a leaf node
        if(!root->left && !root->right) leafs.push_back(root->val);

        helper(root->left, leafs);
        helper(root->right, leafs);
    } 

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1;
        vector<int> r2;

        helper(root1, r1);
        helper(root2, r2);

        return r1 == r2;
    }
};