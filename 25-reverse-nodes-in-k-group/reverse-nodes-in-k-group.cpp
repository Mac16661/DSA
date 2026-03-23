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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;

        // Step 1: Check if there are at least k nodes ahead
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (!check) return head; // less than k nodes, no reverse
            check = check->next;
        }

        // Step 2: Reverse k nodes
        int cnt = k;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr && cnt--) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Step 3: Recursively reverse the rest
        head->next = reverseKGroup(curr, k);

        // Step 4: Return new head after reversal
        return prev;
    }
};