#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int newColor) {

        int n = image.size();          
        int m = image[0].size();       
        int oldColor = image[sr][sc];  
        if (oldColor == newColor)      
            return image;

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;      

        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                
                if (image[nx][ny] == oldColor) {
                    image[nx][ny] = newColor;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};
