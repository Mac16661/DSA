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
    ListNode* helper(ListNode* head) {
        if (!head or !head->next)
            return head;
        
        ListNode* newNode = helper(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newNode;
    }

    ListNode* reverseList(ListNode* head) {
        // Recursive version
        return helper(head);

        // ============================================
        // Doing the iterative version
        if (!head or !head->next)
            return head;

        ListNode* prev = nullptr;

        while (head != nullptr) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }
};