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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> st;

        while(headA != nullptr) {
            st.insert(headA);
            headA = headA->next;
        }

        while(headB != nullptr) {
            if(st.find(headB) != st.end()) {
                return headB;
            }

            headB = headB->next;
        }

        return nullptr;

    }
};