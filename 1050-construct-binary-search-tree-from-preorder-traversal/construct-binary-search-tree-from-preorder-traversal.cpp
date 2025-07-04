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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // If element is smaller then stack st.top()->val ,then st.top()->left = element and push it to stack
        // while current element is greater then st.top()->val, then pop until greater top is reached and last_popped_element->right = current; push it to stack

        // Creating first node
        TreeNode* rootNode = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(rootNode);

        for(int i=1; i<preorder.size(); i++) {
            int cur = preorder[i];

            TreeNode* prev = nullptr;
            while(!st.empty() && st.top()->val <= cur){
                prev = st.top();
                st.pop();
            }

            TreeNode* newNode = new TreeNode(cur);

            if(prev == nullptr) st.top()->left = newNode;
            else prev->right = newNode;

            st.push(newNode);
        }

        return rootNode;
    }
};