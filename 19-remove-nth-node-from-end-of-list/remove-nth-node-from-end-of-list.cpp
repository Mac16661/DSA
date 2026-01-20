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
    int count=0;
public:
    ListNode* helper(ListNode* head, int n) {
        if(head== nullptr) return nullptr;

        ListNode* newNode = helper(head->next, n);
        count++;

        if(count == n) {
            return newNode;
        }

        head->next = newNode;
        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return helper(head,n);
    }
};