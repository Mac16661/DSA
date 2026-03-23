class Solution {
public:
    bool safetyCheck(int row, int col, vector<string>& board) {
        int n = board.size();

        // Check same row on the left
        for (int j = 0; j < col; ++j) {
            if (board[row][j] == 'Q') return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        // Check lower-left diagonal
        for (int i = row + 1, j = col - 1; i < n && j >= 0; ++i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void helper(int col, vector<string>& board, vector<vector<string>>& res) {
        int n = board.size();
        if (col == n) {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (safetyCheck(row, col, board)) {
                board[row][col] = 'Q';
                helper(col + 1, board, res);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));  
        vector<vector<string>> ans;

        helper(0, board, ans);

        return ans;
    }
};
