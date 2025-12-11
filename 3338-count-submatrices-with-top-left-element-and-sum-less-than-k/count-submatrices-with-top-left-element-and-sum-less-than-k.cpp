class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // 2D prefix
        vector<vector<int>> pref(n, vector<int>(m, 0));

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                pref[i][j] = grid[i][j];

                if (i > 0) pref[i][j] += pref[i - 1][j];
                if (j > 0) pref[i][j] += pref[i][j - 1];
                if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];

                if (pref[i][j] <= k) cnt++;
            }
        }

        return cnt;
    }
};
