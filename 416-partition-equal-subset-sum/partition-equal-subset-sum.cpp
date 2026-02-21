class Solution {
public:
    vector<vector<int>> dp;

    bool helper(vector<int>& nums, int idx, int sum, int target) {
        if (sum == target) return true;
        if (idx >= nums.size() || sum > target) return false;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        // take
        bool take = helper(nums, idx + 1, sum + nums[idx], target);

        // not take
        bool notTake = helper(nums, idx + 1, sum, target);

        return dp[idx][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;

        if (total % 2 != 0) return false;

        int target = total / 2;

        dp.resize(nums.size(), vector<int>(target + 1, -1));

        return helper(nums, 0, 0, target);
    }
};
