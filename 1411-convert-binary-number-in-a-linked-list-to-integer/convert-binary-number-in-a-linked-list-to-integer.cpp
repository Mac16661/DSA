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
    // Brute force approach to get the the binary number back in string format

    // Optimal do calculation on the go
    int bToD(ListNode* head, int& cnt) {
        if(head == nullptr) return 0;

        int num = bToD(head->next, cnt);

        if(head->val == 1) {
            num = num + pow(2, cnt);
        }
        cnt++;
        return num;
    }

    int getDecimalValue(ListNode* head) {
        int cnt = 0;
        return bToD(head, cnt);
    }
};