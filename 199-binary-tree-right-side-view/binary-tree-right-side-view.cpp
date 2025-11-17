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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> tree;

        if(root == nullptr) return tree;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();

            int lastVal = q.front()->val;

            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();

                lastVal = node->val;

                // push neighbour nodes
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }

            tree.push_back(lastVal);
         }

         return tree;
    }
};