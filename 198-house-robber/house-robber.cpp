class Solution {
public:
    // just recursion
    int maxSum = 0;
    void helperRec(int i, vector<int>& nums, int sum) {
        // base case
        if(i >= nums.size()) {
            maxSum = max(maxSum, sum);
            return;
        }

        // Take
        helperRec(i+2, nums, sum + nums[i]);

        // Not Take
        helperRec(i+1, nums, sum);
    }

    // Top Down DP 
    int helperDP(int n, vector<int> &nums, vector<int> & dp) {
        // base case
        if(n < 0) {
            return 0;
        }

        // dp
        if(dp[n] != -1) return dp[n];

        // Take
        int t = helperDP(n-2, nums, dp) + nums[n];

        // Not Take
        int nt = helperDP(n-1, nums, dp);

        return dp[n] = max(t, nt);
    }

    int rob(vector<int>& nums) {
        // helperRec(0, nums, 0);
        // return maxSum;

        // Top Down DP
        // int n = nums.size()-1;
        // vector<int> dp(n+1, -1);
        // return helperDP(n, nums, dp);

        // Bottom Up DP
        // int n = nums.size();
        // if(n == 0) return 0;
        // if(n == 1) return nums[0];

        // vector<int> dp(n, 0);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        
        // for(int i=2; i<n; i++) {
        //     int nt = dp[i-1];
        //     int t = dp[i-2] + nums[i];
        //     dp[i] = max(t, nt);
        // } 

        // return dp[n-1];

        // Space optimization
        int prev2 = 0, prev1 = 0;
        for (int num : nums) {
            int curr = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};