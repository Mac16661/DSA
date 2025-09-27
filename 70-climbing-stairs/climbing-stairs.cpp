class Solution {
public:
    int helper(int n, vector<int>& dp) {
        if(n==0) return 1;
        if(n==1) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = helper(n-1, dp) + helper(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);

        // Tabulization
        // dp[0] = 1, dp[1] = 1;
        // for(int i=2; i<=n; i++) {
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];

        // Space optimization

        int prev = 1, prev2 = 1;

        for(int i=2; i<=n; i++) {
            int cnt = prev+prev2;
            prev = prev2;
            prev2 = cnt;
        }
        return prev2;
    }
};