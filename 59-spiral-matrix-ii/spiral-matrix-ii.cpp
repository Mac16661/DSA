class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n, vector<int>(n));
        
        int cnt = 1;
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {

            // top row: left → right
            for (int col = left; col <= right; col++) {
                grid[top][col] = cnt++;
            }
            top++;

            // right column: top → bottom
            for (int row = top; row <= bottom; row++) {
                grid[row][right] = cnt++;
            }
            right--;

            // bottom row: right → left
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    grid[bottom][col] = cnt++;
                }
                bottom--;
            }

            // left column: bottom → top
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    grid[row][left] = cnt++;
                }
                left++;
            }
        }

        return grid;
    }
};
