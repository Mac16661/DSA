class Solution {
public:
    int helper(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) {
        int n = grid.size(), m = grid[0].size();

        // out of bounds → invalid path
        if (i >= n || j >= m) return 1e9;

        // destination cell
        if (i == n-1 && j == m-1) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];

        // visit down
        int down = helper(grid, dp, i+1, j);

        // visit right
        int right = helper(grid, dp, i, j+1);

        return dp[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(grid, dp, 0, 0);
    }
};