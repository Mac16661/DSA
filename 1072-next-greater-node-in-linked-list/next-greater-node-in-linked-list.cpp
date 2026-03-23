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
    // Recursive NGE
    void helper(ListNode* head, vector<int>& nge, stack<int>& st, int i){
        if(head==nullptr) return;

        nge.push_back(0);
        helper(head->next, nge, st, i+1);

        while(!st.empty() && st.top() <= head->val) st.pop();

        if(!st.empty() && st.top()) nge[i] = st.top();

        st.push(head->val);
    }

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nge;
        stack<int> st;

        helper(head, nge, st, 0);

        return nge;
    }
};