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
            head->next = prev;
            return head;
        }

        ListNode* newNode = helper(head->next, head);
        head->next = prev;

        return newNode;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;

        return helper(head,  nullptr); 
    }
};