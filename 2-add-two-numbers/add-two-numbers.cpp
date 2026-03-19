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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = nullptr;
        ListNode* t = ans;

        int carry = 0;
        while (l1 != nullptr or l2 != nullptr or carry) {
            int sum = 0;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            if (carry)
                sum += carry;

            // cout<<sum%10<<endl;
            
            if (t == nullptr){
                t = new ListNode(sum % 10);
                ans = t;
            }
            else {
                t->next = new ListNode(sum % 10);
                t = t->next;
            }

            carry = sum / 10;
        }

        return ans;
    }
};