class Solution {
public:
    // Need to return -> number of ways amount can be formed
    int helper (vector<int>& coins, int idx, int sum, int amt, vector<vector<int>>& dp) {
        if (sum > amt) return 0;

        if (idx >= coins.size()) {
            if (sum == amt)
                return 1;
            return 0;
        }

        if(dp[idx][sum] != -1)
            return dp[idx][sum];

        // not take
        int notTake = helper(coins, idx+1, sum, amt, dp);

        // take (unbounded) -> trick to use same index again and again
        int take = helper(coins, idx, sum+coins[idx], amt, dp);

        return dp[idx][sum] = notTake + take;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return helper(coins, 0, 0, amount, dp);
    }
};