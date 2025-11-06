class Solution {
public:
    int n;
    int minCost = INT_MAX;
    void helper(int i, vector<int>& cost, int sum) {
        if(i>=n) {
            minCost = min(minCost, sum);
            return;
        }

        // take 1 step
        helper(i+1, cost, sum+cost[i]);

        // take 2 step
        helper(i+2, cost, sum+cost[i]);
    }

    int helperRec(int i, vector<int>& cost, vector<int>& dp) {
        if(i>=n) return 0;

        if(dp[i] != -1) return dp[i];

        int st1 = helperRec(i+1, cost, dp) + cost[i];
        int st2 = helperRec(i+2, cost, dp) + cost[i];

        return dp[i] =  min(st1, st2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        // helper(0, cost, 0); // start from step 0
        // helper(1, cost, 0); // or step 1
        // return minCost;

        vector<int> dp(n, -1);
        return min(helperRec(0, cost, dp), helperRec(1, cost, dp));
    }
};