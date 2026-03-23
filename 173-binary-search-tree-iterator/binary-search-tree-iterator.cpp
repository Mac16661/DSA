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
class BSTIterator {
public:
    TreeNode* root;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root): root(nullptr) {
        this->root = root;
        if(root) st.push(root);

    }
    
    int next() {
        TreeNode* temp = st.top();

        // getting to the left most node
        while(temp->left) {
            st.push(temp->left);
            TreeNode* breakNode = temp;
            temp = temp->left;
            breakNode->left = nullptr; // breaking the tree after pushing
        }

        temp = st.top();
        st.pop();

        if(temp->right) {
            st.push(temp->right);
        }

        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */