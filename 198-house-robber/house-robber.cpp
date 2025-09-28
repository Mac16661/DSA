class Solution {
public:
    int helper(int idx, vector<int>& nums, vector<int>& dp, int n) {
        if(idx >= n) return 0;

        if(dp[idx] != -1) return dp[idx];

        int sum = nums[idx];
        int maxi = 0;
        for(int i=idx; i<n; i++) {
            maxi = max(maxi, helper(i+2, nums, dp, n));
        }
        sum+= maxi;

        return dp[idx] = sum;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return max(helper(0, nums, dp, n), helper(1, nums, dp, n));
    }
};