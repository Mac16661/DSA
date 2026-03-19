class Solution {
public:
    ListNode* rev(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* newNode = rev(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newNode;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* headRev = rev(head);

        // Special case: remove first node of reversed list
        if (n == 1) {
            headRev = headRev->next;
        } else {
            ListNode* temp = headRev;

            for (int i = 1; i < n - 1; i++) {
                temp = temp->next;
            }

            if (temp->next)
                temp->next = temp->next->next;
        }

        return rev(headRev);
    }
};