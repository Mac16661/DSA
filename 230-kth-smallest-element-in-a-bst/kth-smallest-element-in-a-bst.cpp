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
    // vector<int> ans;
    int inorder(TreeNode* root, int k, int& cnt) {
        if(root == nullptr) return -1;

        int left = inorder(root->left, k, cnt);

        if(left != -1) return left;

        cnt++;
        if(cnt == k) return root->val;


        return inorder(root->right, k, cnt);
    }

    void inorder(TreeNode* root, int &cnt, int k, int& ans){
        if(root == nullptr) return;

        inorder(root->left, cnt, k , ans);
        // ans.push_back(root->val);
        cnt++;
        if(cnt == k) ans = root->val;
        inorder(root->right, cnt, k , ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return inorder(root, k, cnt);

        // inorder(root);

        // for(auto i:ans) cout<<i<< " ";
        // cout<<endl;

        // return ans[k-1];

        
        int ans = -1;

        inorder(root, cnt, k , ans);
        return ans;
    }
};