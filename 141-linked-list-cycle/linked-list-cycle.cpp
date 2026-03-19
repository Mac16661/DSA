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
    bool hasCycle(ListNode *head) {
        if (!head or !head->next)
            return false;

        // Fast and slow ptr
        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast != nullptr and fast->next != nullptr) {
            if (fast == slow)
                return true;

            fast = fast->next->next;
            slow = slow->next;
        }

        return false;
    }
};