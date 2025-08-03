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

        // Brute
        // std::map<int, int> mpp;

        // while(head != nullptr) {
        //     mpp[head->val]++;
        //     head = head->next;
        // }

        // ListNode* newNode = new ListNode(-1);
        // ListNode* temp = newNode;

        // for(auto mp: mpp) {
        //     if(mp.second <= 1) {
        //         temp->next = new ListNode(mp.first);
        //         temp = temp->next;
        //     }
        //     // cout<<mp.first<<" "<<mp.second<<endl;
        // }

        // return newNode->next;

        // Optimal
        ListNode* dummy = new ListNode(0, head); // Handles head removal
        ListNode* prev = dummy;

        while (head != NULL) {
            // Detect duplicates
            if (head->next != NULL && head->val == head->next->val) {
            while (head->next != NULL && head->val == head->next->val) {
                    head = head->next; 
                }
                prev->next = head->next; // Remove entire group
            } else {
                prev = prev->next; // Unique value, move prev forward
            }
            head = head->next; // Move head forward in all cases
        }

        return dummy->next;
    }
};