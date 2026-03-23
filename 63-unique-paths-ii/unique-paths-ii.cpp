class Solution {
public:
    int helper(int m, int n, int i, int j,
               vector<vector<int>>& grid,
               vector<vector<int>>& dp) {

        // Out of bounds
        if (i >= m || j >= n) return 0;

        // Hit obstacle
        if (grid[i][j] == 1) return 0;

        // Reached destination
        if (i == m - 1 && j == n - 1) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int down = helper(m, n, i + 1, j, grid, dp);
        int right = helper(m, n, i, j + 1, grid, dp);

        return dp[i][j] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(m, n, 0, 0, obstacleGrid, dp);
    }
};
