class Solution {
public:
    // Use BFS and we will try from distance 0 th cell to reach 1 if min found then update
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        // Put in queue which index are already 0
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0)
                   { 
                    q.push({i, j});
                    dist[i][j] = 0;
                    } // setting dist value
            }
        }

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(auto d: dir) {
                int nr = r + d.first;
                int nc = c + d.second;

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 1) {
                    // This is the case when dist is not initialize
                    if(dist[nr][nc] == -1) {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                    else{
                        dist[nr][nc] = min(dist[nr][nc], dist[r][c] + 1);
                    }

                }
            }
        }
        return dist;
    }
};