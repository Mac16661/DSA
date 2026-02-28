class Solution {
public:
    // Without memoization 
    // int helper(vector<int>& nums, int idx,int sum, int target) {
    //     if(idx >= nums.size()) {
    //         if(sum == target) return 1;
    //         return 0;
    //     }

    //     // add
    //     int add = helper(nums, idx+1, sum + nums[idx], target);

    //     // Sub
    //     int sub = helper(nums, idx+1, sum - nums[idx], target);

    //     return add + sub;
    // }
    
    // With memoization 
    int helper(vector<int>& nums, unordered_map<string,int>& dp,int idx,int sum, int target) {
        if(idx >= nums.size()) {
            if(sum == target) return 1;
            return 0;
        }

        string key = to_string(idx)+ " | " + to_string(sum);

        if(dp.count(key)) return dp[key];

        // add
        int add = helper(nums, dp, idx+1, sum + nums[idx], target);

        // Sub
        int sub = helper(nums, dp, idx+1, sum - nums[idx], target);

        return dp[key] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int> dp;
        return helper(nums, dp, 0, 0, target);
    }
};