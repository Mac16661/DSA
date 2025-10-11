class Solution {
public:
    int findPath(int row, int col, int m, int n, vector<vector<int>> &dp, vector<vector<int>>& obstacleGrid) {
        // Out of bounds or obstacle
        if (row >= m || col >= n || obstacleGrid[row][col] == 1)
            return 0;

        if (row == m - 1 && col == n - 1)
            return 1;

        if (dp[row][col] != -1)
            return dp[row][col];

        int down = findPath(row + 1, col, m, n, dp, obstacleGrid);
        int right = findPath(row, col + 1, m, n, dp, obstacleGrid);

        return dp[row][col] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // If start or end is blocked, no path exists
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        // return findPath(0, 0, m, n, dp, obstacleGrid);
        dp[0][0] = 1;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) continue; // base case
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                int up = 0, left = 0;

                if(i>0) up += dp[i-1][j];
                if(j>0) left += dp[i][j-1];

                dp[i][j] = up+left;
            }
        }

        return dp[m-1][n-1];
    }
};
