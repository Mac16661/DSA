class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Find Previous Less Element for each index
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }

        // Clear stack for next usage
        while (!st.empty()) st.pop();

        // Find Next Less Element for each index
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }

        // Evaluate maximum score for ranges that include k
        int maxScore = 0;
        for (int i = 0; i < n; i++) {
            if (left[i] <= k && k <= right[i]) {
                int length = right[i] - left[i] + 1;
                int score = nums[i] * length;
                maxScore = max(maxScore, score);
            }
        }

        return maxScore;
    
    }
};