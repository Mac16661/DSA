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
    bool checkLeftSubtree(TreeNode* next, TreeNode* root) {
        if(next==nullptr) return true;

        if(next->val >= root->val) return false;

        if(!checkLeftSubtree(next->left, root)) return false;
        if(!checkLeftSubtree(next->right, root)) return false;

        return true;
    }

    bool checkRightSubtree(TreeNode* next, TreeNode* root) {
        if(next == nullptr) return true;

        if(next->val <= root->val) return false;

        if(!checkRightSubtree(next->left, root)) return false;
        if(!checkRightSubtree(next->right, root)) return false;
        
        return true;
    }

    bool valid(TreeNode* node, long left, long right) {
        if (!node) {
            return true;
        }
        if (!(left < node->val && node->val < right)) {
            return false;
        }
        return valid(node->left, left, node->val) && valid(node->right, node->val, right);
    }

    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;

        // Brute force 0(n)^2
        // TreeNode* temp = root;

        // // Performing dfs
        // stack<TreeNode*> st;
        // st.push(root);

        // while(!st.empty()) {
        //     int size = st.size();

        //     for(int i=0; i<size; i++) {
        //         TreeNode* f = st.top();
        //         st.pop();

        //         if(f->right) {
        //             st.push(f->right);
        //             if(!checkRightSubtree(f->right, f)) return false;
        //         }

        //         if(f->left) {
        //             st.push(f->left);
        //             if(!checkLeftSubtree(f->left, f)) return false;
        //         }
        //     }
        // }

        // return true;

        // Optimal

        return valid(root, LONG_MIN, LONG_MAX); // root, lower bound, upper bound
    }
};