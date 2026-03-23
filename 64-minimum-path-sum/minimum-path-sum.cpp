class Solution {
public:
    // Brute Expore all paths and store the min among them
    
    // Better
    int helper(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j, int m, int n)  {
        // Destination
        if (i == m-1 && j == n-1) {
            return grid[i][j];
        }

        if(dp[i][j] != -1) return dp[i][j];

        int down = INT_MAX;
        int right = INT_MAX;

        // Move Down
        if (i + 1 < m) {
            down = helper(grid, dp, i + 1, j, m, n);
        }

        // Move Right
        if (j + 1 < n) {
            right = helper(grid, dp, i, j + 1, m, n);
        }

        return dp[i][j] = min(down, right) + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
      
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(grid, dp, 0, 0, m, n);
    }
};