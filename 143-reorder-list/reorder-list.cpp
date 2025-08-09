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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Push second half into stack
        ListNode* second = slow->next;
        slow->next = nullptr;
        stack<ListNode*> st;
        while (second) {
            st.push(second);
            second = second->next;
        }

        // Merge first half and reversed second half
        ListNode* curr = head;
        while (!st.empty()) { // While elements are there in the stack
            ListNode* nextNode = st.top();
            st.pop();

            nextNode->next = curr->next;
            curr->next = nextNode;

            curr = nextNode->next; // move two steps forward
            if (!curr) break;
        }

    }
};