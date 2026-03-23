/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> graph;

    void buildGraph(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        if (parent) {
            graph[node].push_back(parent);
            graph[parent].push_back(node);
        }
        buildGraph(node->left, node);
        buildGraph(node->right, node);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(root, nullptr); // step 1: build adjacency list

        queue<pair<TreeNode*, int>> q; // node, distance
        unordered_set<TreeNode*> visited;

        q.push({target, 0});
        visited.insert(target);

        vector<int> result;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (dist == k) {
                result.push_back(node->val);
            }

            for (TreeNode* neighbor : graph[node]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push({neighbor, dist + 1});
                }
            }
        }

        return result;
    }
};