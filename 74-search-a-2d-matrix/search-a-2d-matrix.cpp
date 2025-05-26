class Solution {
public:
    bool rowSearch(vector<vector<int>>& matrix, int target, int row, int m) {
        int left = 0, right = m-1;

        while(left <= right) {
            int mid = (left+right) / 2;

            if(matrix[row][mid] == target) {
                return true;
            }

            if(matrix[row][mid] < target) {
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Find floor using binary search on first column
        int top = 0, bottom = matrix.size()-1;

        while(top <= bottom) {
            int mid = (top+bottom) / 2;

            if(matrix[mid][0] <= target) {
                if(matrix[mid][0] == target) return true;
                // call binary search in row and return if true
                if(rowSearch(matrix, target, mid, m)) return true;
                top = mid+1;
            }else {
                bottom = mid-1;
            }
        }


        return false;
    }
};