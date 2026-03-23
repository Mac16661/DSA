class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // We will try to remove both loop and extra space
        // vector<vector<int>> visited(n, vector<int>(m, 0));
        // for (int i=0; i<n; i++) {
        //     for (int j=0; j<m; j++) {
        //         if (grid[i][j] == '0')
        //             visited[i][j] = 1;
        //     }
        // }

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        int cnt = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                
                if (grid[i][j] == '1') {
                    cnt++;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();


                        for (auto d: dir) {
                            int nr = r + d.first;
                            int nc = c + d.second;


                            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1') {
                                q.push({nr, nc});
                                grid[nr][nc] = '0';  // Marking visited
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};