class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && (i==0 || i == n-1 || j == 0 || j == m-1))
                {
                    q.push({i, j});
                    grid[i][j] = 0; 
                }// Marking boundary cells visited 
            }
        }

        cout<< q.size()<<endl;

        int cnt = 0;
        vector<pair<int,int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto d:dir) {
                int nr = r + d.first;
                int nc = c + d.second;


                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                    q.push({nr, nc});
                    grid[nr][nc] = 0;   // Marking it visited if condition above is true
                    cout<<nr<<" , "<<nc<<endl;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    cnt++;
            }
        }

        return cnt;
    }
};