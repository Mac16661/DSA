class Solution {
public:
    ListNode* rev(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = rev(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    int pairSum(ListNode* head) {
        // Step 1: find middle
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: reverse second half
        ListNode* second = rev(slow);
        
        // Step 3: pair sums
        int maxi = 0;
        ListNode* first = head;
        while (second) {
            maxi = max(maxi, first->val + second->val);
            first = first->next;
            second = second->next;
        }
        return maxi;
    }
};
