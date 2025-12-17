class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            // build histogram
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }

            // rearrange columns
            vector<int> sorted = height;
            sort(sorted.begin(), sorted.end(), greater<int>());

            // compute max area
            for (int k = 0; k < m; k++) {
                maxArea = max(maxArea, sorted[k] * (k + 1));
            }
        }

        return maxArea;
    }
};
