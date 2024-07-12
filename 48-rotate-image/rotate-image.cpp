class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Transpose the arr
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for(int i=0; i<matrix.size(); i++) {
            int left=0,right=matrix[0].size()-1;

            while(left < right) {
                swap(matrix[i][left], matrix[i][right]);
                right--;
                left++;
            }

        }
    }
};