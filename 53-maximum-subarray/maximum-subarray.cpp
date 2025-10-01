class Solution {
public:
    int helper(int idx, vector<int>& nums, int n, vector<int>& dp) {
        if(idx >= n) return 0;

        if(dp[idx] != -1) return dp[idx];

        // take
        int take = nums[idx] + helper(idx+1, nums, n, dp);

        // not take
        int notTake = nums[idx];

        return dp[idx] = max(take, notTake);
    }

    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        vector<int> dp(n, -1);

        for (int i = 0; i < n; i++) {
            ans = max(ans, helper(i, nums, n, dp));
        }

        return ans;
    }
};