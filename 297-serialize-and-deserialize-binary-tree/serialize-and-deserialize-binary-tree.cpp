/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int i = 0;

    void serializeHelper(TreeNode* root, string& bt) {
        if (!root) {
            bt += "n ";
            return;
        }
        bt += to_string(root->val) + " ";
        serializeHelper(root->left, bt);
        serializeHelper(root->right, bt);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string bt;
        serializeHelper(root, bt);
        return bt;
    }

    TreeNode* deserializeHelper(vector<string>& nodes) {
        if (nodes[i] == "n") {
            i++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(nodes[i++]));
        root->left = deserializeHelper(nodes);
        root->right = deserializeHelper(nodes);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if (s.empty()) return nullptr;

        // cout<<s<<endl;
        stringstream ss(s);
        vector<string> nodes;
        string temp;
        while (ss >> temp) {
            nodes.push_back(temp);
        }
        i = 0;
        return deserializeHelper(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));