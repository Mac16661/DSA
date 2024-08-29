/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;
        ListNode* prev;
        // cout<<nextNode->val;
        while(nextNode != NULL){
            node->val = nextNode->val;
            nextNode = nextNode->next;
            prev = node;
            node = node->next;
        }
        // delete node;
        // cout<<prev->val;
        prev->next = NULL;
        delete node;
        // cout<<prev->next->val;
    }
};