class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Calculate all the rotten org(push it to queue) and also coutn the fresh one
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;
        int time = 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If rotten push it to queue for multisource dfs traversal
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                if (grid[i][j] == 1)
                    fresh++;
            }
        }

       vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while(!q.empty()) {
            int size = q.size(); // Crutial for multisource bfs
            bool rotten = false;

            for (int i = 0; i < size; i++) {
                auto [r,c] = q.front();
                q.pop();

                for (auto d:dir) {
                    int nr = r + d.first;
                    int nc = c + d.second;

                    if (nc>=0 && nc<m &&  nr>=0 && nr<n && grid[nr][nc] == 1) {
                        q.push({nr, nc});
                        grid[nr][nc] = 2;
                        fresh--;
                        rotten = true;
                    }
                }
            }
            if (rotten)
                time++;
        }

        return fresh==0? time:-1;
    }
};