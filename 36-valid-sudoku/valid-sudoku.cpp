class Solution {
public:
    bool checkRows(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++) { // row
            unordered_set<char> st;
            for(int j=0; j<m; j++) { // cols
                if(board[i][j] == '.') continue;
                else if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool checkCols(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<m; i++) { // col
            unordered_set<char> st;
            for(int j=0; j<n; j++) { // rows
                if(board[j][i] == '.') continue;
                else if(st.count(board[j][i])) return false;
                st.insert(board[j][i]);
            }
        }
        return true;
    }

    bool checkSubMat(vector<vector<char>>& board) {
        for(int sqr = 0; sqr<9; sqr++) {
            unordered_set<char> st;

            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    int row = (sqr/3) * 3 + i;
                    int col = (sqr%3) * 3 + j;
                    if(board[row][col] == '.') continue;
                    if(st.count(board[row][col])) return false;
                    st.insert(board[row][col]);
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // brute force

        // check all rows
        // check all cols
        // check all 3*3 sub matrices 
        return checkRows(board) && checkCols(board) && checkSubMat(board);
    }
};