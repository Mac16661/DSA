class Solution {
public:
    int findPath(int row, int col, int m, int n, vector<vector<int>> &dp) {
        if (row == m - 1 && col == n - 1)
            return 1;

        if (row >= m || col >= n)
            return 0;

        if (dp[row][col] != -1)
            return dp[row][col];

        int down = findPath(row + 1, col, m, n, dp);
        int right = findPath(row, col + 1, m, n, dp);

        return dp[row][col] = down + right;
    }

    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return findPath(0, 0, m, n, dp);
        vector<int> prev(n, 1), curr(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                curr[j] = curr[j - 1] + prev[j];
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};
