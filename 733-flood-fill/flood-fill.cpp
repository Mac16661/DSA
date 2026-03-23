class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // BFS based
        int n = image.size();
        int m = image[0].size();
        int srcColor = image[sr][sc];

        if (srcColor == color)  return image; // Do we need this?

        queue<pair<int, int>> q;
        image[sr][sc] = color;
        q.push({sr, sc});

        vector<pair<int, int>> dir =  {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        while (!q.empty()) {
            int size = q.size(); // if want to traverse level wise
            auto [r, c] = q.front();
            q.pop();

                for(auto d:dir) {
                    int nr = r + d.first;
                    int nc = c + d.second;

                    // Trying to move in all directions []image[nr][nc] == srcColor] that what stop this alog to go in infinite loop
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == srcColor) {
                        q.push({nr, nc});
                        image[nr][nc] = color;
                    }
                }
            
        }

        return image;
    }
};