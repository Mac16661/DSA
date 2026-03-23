class Solution {
public:
    int helper(int m, int n, int i, int j, vector<vector<int>>& dp) {
        if (i == m && j == n) {
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int way = 0;
        if (i < m) way += helper(m, n, i + 1, j, dp);
        if (j < n) way += helper(m, n, i, j + 1, dp);
        return dp[i][j] = way;
    }

    int uniquePaths(int m, int n) {  
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(m - 1, n - 1, 0, 0, dp);
    }
};
