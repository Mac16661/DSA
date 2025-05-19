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

    // better approach
    void setZeroes(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        
        vector<int> Row(N, -1);
        vector<int> Col(M, -1);

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(matrix[i][j] == 0) {
                    Row[i] = 0;
                    Col[j] = 0;
                }
            }
        }

        // Setting row zero
        for(int i=0; i<N; i++) {
            if(Row[i] == 0) {
                for(int j=0; j<M; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Setting col zero
        for(int j=0; j<M; j++) {
            if(Col[j] == 0) {
                for(int i=0; i<N; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};