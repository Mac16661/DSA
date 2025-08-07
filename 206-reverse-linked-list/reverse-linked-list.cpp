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
    ListNode* helper(ListNode* head, ListNode* prev) {
        if(head->next == nullptr){
            return new ListNode(head->val, prev);
        }

        ListNode* newHead = helper(head->next, head);
        head->next = prev;
        return newHead;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;

        // Recursive approach
        // return helper(head, nullptr);
    }
};