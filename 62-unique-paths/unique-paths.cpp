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
        // vector<int> prev(n, 1), curr(n, 1);

        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++) {
        //         curr[j] = curr[j - 1] + prev[j];
        //     }
        //     prev = curr;
        // }

        // return prev[n - 1];

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue; // Skip the rest of the loop and continue with the next iteration.
                } 
                int up = 0;
                int left = 0;

                if (i > 0)
                    up = dp[i - 1][j];

                
                if (j > 0)
                    left = dp[i][j - 1];

                // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.
                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
};
