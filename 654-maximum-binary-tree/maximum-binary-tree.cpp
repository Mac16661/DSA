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
    int findMax(vector<int>& nums) {
        int maxInd = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[maxInd] < nums[i]) maxInd = i;
        }

        return maxInd;
    }

    // TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    //     if (nums.empty()) return nullptr;

    //     int maxInd = findMax(nums);
    //     TreeNode* root = new TreeNode(nums[maxInd]);

    //     vector<int> left(nums.begin(), nums.begin() + maxInd);
    //     vector<int> right(nums.begin() + maxInd + 1, nums.end());

    //     root->left = constructMaximumBinaryTree(left);
    //     root->right = constructMaximumBinaryTree(right);

    //     return root;
    // }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // TODO:  if some element is greater then, find a  number  which is smaller then current but greater then rest and pop the stack until we find it . once we find it set it to curr->left; if some elemnt is still there in stack which is greater then current,then make it st.top()-> right
        stack<TreeNode*> st;

        for(auto num : nums) {
            TreeNode* newNode = new TreeNode(num);

            // stack in increasing order
            while(!st.empty() && st.top()->val < num) {
                newNode->left = st.top();
                st.pop();
            }

            if(!st.empty()) {
                st.top()->right = newNode;
            }

            st.push(newNode);

        }

        while(st.size() != 1) st.pop(); // retriving the max element in the stack which wll be in th ebottom
        
        return st.top();
    }
};