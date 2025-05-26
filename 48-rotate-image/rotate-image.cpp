class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp = matrix; //deep  copy

        for(int c = 0; c<temp.size(); c++) {
            vector<int> t;
            for(int r = temp[0].size()-1; r>= 0; r--) {
                t.push_back(temp[r][c]);
            }
            matrix[c] = t;
        }

    }
};