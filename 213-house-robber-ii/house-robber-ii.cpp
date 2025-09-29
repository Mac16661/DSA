class Solution {
public:
    int helper(int idx, vector<int>& nums, vector<int>& dp, int end) {
        if(idx > end) return 0;

        if(dp[idx] != -1) return dp[idx];

        // rob current house
        int rob = nums[idx] + helper(idx+2, nums, dp, end);

        // rob next one
        int notRob = helper(idx+1, nums, dp, end);

        return dp[idx] = max(rob, notRob);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[n-1];
        if(n==2) return max(nums[0], nums[1]);

        vector<int> dp1(n, -1), dp2(n, -1);
        return max(helper(0, nums, dp1, n-2), helper(1, nums, dp2, n-1));
    }
};