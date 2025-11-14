class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> nodes;

            // collect all nodes in this level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                nodes.push_back(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // reverse only odd levels
            if (level % 2 == 1) {
                int i = 0, j = size - 1;
                while (i < j) {
                    swap(nodes[i]->val, nodes[j]->val);
                    i++;
                    j--;
                }
            }

            level++;
        }

        return root;
    }
};
