class Solution {
public:
    bool helper(vector<int>& nums, vector<vector<int>>& dp, int idx, int sum, int target) {
        if(sum == target) return true;
        if(idx >= nums.size()) return false;

        if(dp[idx][sum] != -1) return dp[idx][sum];

        // not take
        bool notTake = helper(nums, dp, idx+1, sum, target);

        bool take = false;
        if(sum+nums[idx] <= target) {
            take = helper(nums, dp, idx+1, sum+nums[idx], target);
        }

        return dp[idx][sum] =  notTake || take;
    }

    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int x: nums) target += x;

        if (target % 2 != 0) return false;
        target /=2;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target, -1));
        return helper(nums, dp, 0, 0, target); 
    }
};