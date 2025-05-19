class Solution {
public:
    void setRowCol(int i, int j, vector<vector<int>>& newMat) {
        // Setting row zero
        for(int k=0; k<newMat[0].size(); k++) {
            newMat[i][k] = 0;
        }

        // Setting col zero
        for(int k=0; k<newMat.size(); k++) {
            newMat[k][j] = 0;
        }


    }

    void setZeroes(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        // initialize it with zero
        // vector<vector<int>> newMat(N, (matrix, 0));

        //Deep copy
        vector<vector<int>> newMat = matrix;

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(matrix[i][j] == 0) {
                    setRowCol(i, j, newMat);
                }
            }
        }

        matrix = newMat;
    }
};