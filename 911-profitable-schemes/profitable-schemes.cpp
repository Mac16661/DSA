class Solution {
public:
    int profitableSchemes(const int N, const int minProfit, const vector<int>& group, const vector<int>& profit) {
        const int M = profit.size();
        constexpr int MOD = 1e9 + 7;
        vector<vector<long>> dp(N + 1, vector<long>(minProfit + 1, 0));

        for (int i = 0; i <= N; ++i) {
            dp[i][0] = 1; // base case
        }

        for (int i = M - 1; i >= 0; --i) {
            const int group_sz = group[i], v = profit[i];
            for (int j = N; j >= group_sz; --j) {
                for (int p = minProfit; p >= 0; --p) {
                    dp[j][p] = (dp[j][p] + dp[j - group_sz][max(p - v, 0)]) % MOD;
                }
            }
        }
        return dp[N][minProfit];
    }
};