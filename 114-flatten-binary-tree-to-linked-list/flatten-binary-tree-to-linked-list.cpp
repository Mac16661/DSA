class Solution {
public:
    TreeNode* flattenH(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* temp = root->right;
        root->right = flattenH(root->left);

        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        while (curr) {
            prev = curr;
            curr = curr->right;
        }

        prev->right = flattenH(temp);
        root->left = nullptr; 
        return root;   
    }

    void flatten(TreeNode* root) {
        flattenH(root);
    }
};
