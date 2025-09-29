class Solution {
public:
    int helper(int idx, vector<int>& nums, vector<int>& dp, int n) {
        if(idx >= n) return 0;

        if(dp[idx] != -1) return dp[idx];

        // pick 
        int take = nums[idx] + helper(idx+2, nums, dp, n);

        // not pick
        int notTake = helper(idx+1, nums, dp, n);

        return dp[idx] = max(take, notTake);
    } 

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(0, nums, dp, n);
    }
};