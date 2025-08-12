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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;

        // Deletion logic
        if(root->val == key) {

            if(!root->left && !root->right) { // where root have no child, just remove the root node
                delete root;
                return nullptr;
            }else if(root->left && root->right) { // when have both child
                TreeNode* temp = root->right;
                while (temp->left) {
                    temp = temp->left;
                }

                // Replace root value with successor's value
                root->val = temp->val;

                // Delete successor node from right subtree
                root->right = deleteNode(root->right, temp->val);
            }else { // if only one child is present
                if(root->left) {
                    TreeNode* temp = root;
                    root = root->left;
                    delete temp;
                }else {
                   TreeNode* temp = root;
                    root = root->right;
                    delete temp; 
                }
            }

        }else if(root->val > key ) { 
            root->left = deleteNode(root->left, key);
        }else { // where root->val < key
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};