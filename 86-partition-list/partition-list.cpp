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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(0);
        ListNode* after = new ListNode(0);
        ListNode* b_curr = before;
        ListNode* a_curr = after;

        while(head != nullptr) {
            if(head->val < x) {
                b_curr->next = head;
                b_curr = b_curr->next;
            }else {
                a_curr->next = head;
                a_curr = a_curr->next;
            }
            head = head->next;
        }

        // merging 
        a_curr->next = nullptr;
        b_curr->next = after->next;

        return before->next;
    }
};