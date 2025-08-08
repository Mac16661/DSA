/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // This cant make it hight balanced bst
    TreeNode* insertBST(TreeNode* root, int val) {
        if(root == nullptr) {
            return new TreeNode(val);
        }

        // if smaller than root then left
        if(val < root->val) {
            root->left = insertBST(root->left, val);
            return root;
        }
        else if(val > root->val) { // if bigger than root then right subtree
            root->right = insertBST(root->right, val);
            return root;
        }

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return new TreeNode(head->val);

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slow_prev = nullptr;

        while (fast && fast->next) {
            slow_prev = slow;
            slow = slow->next;          // move 1 step
            fast = fast->next->next;    // move 2 steps
        }

        TreeNode* root = new TreeNode(slow->val);
        
        slow_prev->next = nullptr;

       root->left = sortedListToBST(head);
       root->right = sortedListToBST(slow->next);

        return root;
    }
};