class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        unordered_set<int> st;

        for(auto num:nums) st.insert(num);

        for (int num : st) {
            if (!st.count(num - 1)) {  // Only start of a sequence
                int curr = num;
                int temp = 1;

                while (st.count(curr + 1)) {
                    curr++;
                    temp++;
                }

                cnt = max(cnt, temp);
            }
        }

        return cnt;
    }
};