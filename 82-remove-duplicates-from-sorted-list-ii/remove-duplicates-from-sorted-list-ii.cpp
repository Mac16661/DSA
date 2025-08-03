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
    ListNode* deleteDuplicates(ListNode* head) {
        // Traverse through list chech if curr->next->val == curr->val: temp = curr->next; curr->next = curr->next->next; delete temp; do it until curr->next != nullpter

        // Brute
        std::map<int, int> mpp;

        while(head != nullptr) {
            mpp[head->val]++;
            head = head->next;
        }

        ListNode* newNode = new ListNode(-1);
        ListNode* temp = newNode;

        for(auto mp: mpp) {
            if(mp.second <= 1) {
                temp->next = new ListNode(mp.first);
                temp = temp->next;
            }
            // cout<<mp.first<<" "<<mp.second<<endl;
        }

        return newNode->next;
    }
};