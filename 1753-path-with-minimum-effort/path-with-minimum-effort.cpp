class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<int>> effort (n, vector<int>(m, INT_MAX)); // storing best effort
        effort[0][0] = 0;

        pq.push({0,0,0}); // currEffort, row, col (src node)

        vector<int> X = {-1, 1, 0, 0};
        vector<int> Y = {0, 0, -1, 1};

        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int currEffort = cur[0], row = cur[1], col = cur[2];

            if(row == n-1 && col == m-1){
                return currEffort;
            }

            for(int i=0; i<4; i++) {
                int nr = row + X[i], nc = col + Y[i];

                if(nr >=0 && nc >=0 && nr < n && nc < m) {
                    int diff = abs(heights[row][col] - heights[nr][nc]);
                    int newEffort = max(currEffort, diff);

                    if(newEffort < effort[nr][nc]) {
                        effort[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }
        return 0;
    }
};