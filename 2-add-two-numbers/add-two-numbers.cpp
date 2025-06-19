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
    int carry=0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr && carry ==0) {
            return nullptr;
        }

        int val = carry;

        if(l1){
           val += l1->val;
           l1 = l1->next;
        }

        if(l2){
            val += l2->val;
            l2 = l2->next;
        }
        
        
        ListNode* newNode = new ListNode(val%10);
        cout<<newNode->val<<" ";
        carry = val/10;
        newNode->next = addTwoNumbers(l1, l2);

        return  newNode;
    }
};