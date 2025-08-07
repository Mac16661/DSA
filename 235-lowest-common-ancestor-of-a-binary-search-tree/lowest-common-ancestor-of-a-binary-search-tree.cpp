/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void BSTPath(TreeNode* root, TreeNode* t, vector<TreeNode*>& path) {
        if(root == nullptr) return;
        path.push_back(root);

        if(root == t) return;

        if(t->val > root->val) BSTPath(root->right, t, path);
        else BSTPath(root->left, t, path);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // vector<TreeNode*> pathp;
        // vector<TreeNode*> pathq;

        // BSTPath(root, p, pathp);
        // BSTPath(root, q, pathq);

        // for(int i=pathp.size()-1; i>=0; i--) {
        //     for(int j=pathq.size()-1; j>=0; j--) {
        //         if(pathp[i]->val == pathq[j]->val){
        //             return pathp[i];
        //         }
        //     }
        // }

        // Optimal code

        if(root == nullptr) return root;
        int curr = root->val;

        if(curr < p->val && curr < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }else if(curr > p->val && curr > q->val) {
            return lowestCommonAncestor(root->left, p , q);
        }else {
            return root;
        }

        return nullptr;
    }
};