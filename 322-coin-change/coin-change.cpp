class Solution {
public:
    int helper(vector<int>& coins,
               vector<vector<int>>& dp,
               int idx,
               int remaining) {

        if (remaining == 0)
            return 0;

        if (idx < 0 || remaining < 0)
            return 1e9;   // large number instead of INT_MAX

        if (dp[idx][remaining] != -1)
            return dp[idx][remaining];

        // Not take
        int notTake = helper(coins, dp, idx - 1, remaining);

        // Take (unbounded, so stay at same index)
        int take = 1 + helper(coins, dp, idx, remaining - coins[idx]);

        return dp[idx][remaining] = min(notTake, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int res = helper(coins, dp, n - 1, amount);

        return res >= 1e9 ? -1 : res;
    }
};