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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;
        while(!q.empty()) {
            vector<int> level;
            int size = q.size(); // current level

            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);
                 // left -> right
                    if(curr->left!=NULL) {
                        q.push(curr->left);
                    }

                    if(curr->right!=NULL) {
                        q.push(curr->right);
                    }
            }
            if(cnt%2==0) reverse(level.begin() ,level.end());
            ans.push_back(level);
            cnt++;
        }
        return ans;
    }
};