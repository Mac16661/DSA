class Solution {
public:
    int helper(int idx, int sum, vector<int>& nums, int target, vector<vector<int>>& dp, int offset) {
        if (idx == nums.size()) {
            return (sum == target) ? 1 : 0;
        }

        if (dp[idx][sum + offset] != -1) return dp[idx][sum + offset];

        int add = helper(idx + 1, sum + nums[idx], nums, target, dp, offset);
        int sub = helper(idx + 1, sum - nums[idx], nums, target, dp, offset);

        return dp[idx][sum + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums) total += x;

        if (abs(target) > total) return 0;

        int offset = total; 
        vector<vector<int>> dp(nums.size(), vector<int>(2 * total + 1, -1));

        return helper(0, 0, nums, target, dp, offset);
    }
};
