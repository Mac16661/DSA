class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<vector<int>> tri(numRows+1);

        for (int i = 0; i <= numRows; i++) {
            tri[i].resize(i + 1);   
            tri[i][0] = tri[i][i] = 1;

            for (int j = 1; j < i; j++) {
                tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
            }
        }

        return tri[numRows];
    }
};