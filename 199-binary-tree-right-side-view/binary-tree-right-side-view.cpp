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
        vector<int> rightSide;
        if(root == nullptr) return rightSide;
        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> level;            

            for(int i=0; i<size; i++) {
                TreeNode* p = q.front();
                q.pop();

                level.push_back(p->val);

                if(p->left != nullptr) {
                    q.push(p->left);
                }

                if(p->right != nullptr) {
                    q.push(p->right);
                }
            }
            ans.push_back(level);
        }
        
        for(auto i : ans) {
            
                int n = i.size()-1;
                rightSide.push_back(i[n]);
            
        }

        return rightSide;
    }
};