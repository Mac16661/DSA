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
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        if(r1 == nullptr || r2 == nullptr) {
            return r1 == r2;
        }

        if(r1->val != r2->val) return false;
        if(!isSameTree(r1->left, r2->left)) return false;
        if(!isSameTree(r1->right, r2->right)) return false;

        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;

        if(root->val == subRoot->val) {
            if(isSameTree(root, subRoot)) return true;
        }

        if(isSubtree(root->left, subRoot)) return true;
        if(isSubtree(root->right, subRoot)) return true;

        return false;
    }
};