class Solution {
public:
    int helper(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int take = helper(nums, i+2, dp) + nums[i];

        int notTake = notTake = helper(nums, i+1, dp);

        return dp[i] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        // It can choose to rob the current idx or skip it and choose to rob the next one

        return helper(nums, 0, dp);
    }
};