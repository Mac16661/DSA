class Solution {
public:
    int helper(int idx, vector<int>& cost, vector<int>& dp) {
        if(idx >= cost.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        // take 1 step
        int one = cost[idx] + helper(idx+1, cost, dp);

        // take 2 steps
        int two = cost[idx] + helper(idx+2, cost, dp);

        return dp[idx] = min(one, two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);

        return min(helper(0, cost, dp), helper(1, cost, dp));
    }
};