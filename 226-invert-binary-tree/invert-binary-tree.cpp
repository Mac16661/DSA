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
    // Just inverting the valuse will not work
    // TreeNode* invertTree(TreeNode* root) {
    //     // level order traversal
    //     if(root == nullptr) return root;

    //     queue<TreeNode*> q;
    //     q.push(root);

    //     // 

    //     while(!q.empty()) {
    //         int size = q.size();
    //         vector<TreeNode*> level;

    //         for(int i=0; i<size; i++) {
    //             TreeNode* node = q.front();
    //             level.push_back(node);
    //             q.pop();

    //             if(node == nullptr) continue;

    //             // if(node->left != nullptr) {
    //                 q.push(node->left);
    //             // }

    //             // if(node->right != nullptr) {
    //                 q.push(node->right);
    //             // }
    //         }

    //         // swaping value of level
    //         int i = 0, j = level.size() -1;

    //         while(i<=j){
    //             // cout<<level[i]->val<<" -> " << level[j]->val<<endl;
    //             while(i < level.size() && level[i] == nullptr) i++;
    //             while(j >=0 && level[j] == nullptr) j--;
    //             if(i<level.size() && j>=0)
    //                 swap(level[i]->val, level[j]->val);
    //             i++;
    //             j--;
    //         }
            
    //     }
    //     return root;
    // }

    // need to invert the tree nodes
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;

        TreeNode* tempNode = root->left;
        root->left = root->right;
        root->right = tempNode;

        invertTree(root->right);
        invertTree(root->left);

        return root;
    }
};