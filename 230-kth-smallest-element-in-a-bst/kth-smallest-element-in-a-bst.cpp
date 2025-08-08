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
    vector<int> ans;
    int inorder(TreeNode* root, int k, int cnt) {
        if(root == nullptr) return -1;

        int left = inorder(root->left, k, cnt);

        if(left != -1) return left;

        cnt++;
        if(cnt == k) return root->val;


        int right = inorder(root->right, k, cnt);

        if(right != -1) return right;

        return -1;
    }

    void inorder(TreeNode* root){
        if(root == nullptr) return;

        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        // return inorder(root, k, 0);

        inorder(root);

        for(auto i:ans) cout<<i<< " ";
        cout<<endl;

        return ans[k-1];
    }
};