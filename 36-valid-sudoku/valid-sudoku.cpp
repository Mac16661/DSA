class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                char ch = board[r][c];
                if (ch == '.') continue;

                int boxId = (r/3)*3 + (c/3);

                if (rows[r].count(ch) || cols[c].count(ch) || boxes[boxId].count(ch))
                    return false;

                rows[r].insert(ch);
                cols[c].insert(ch);
                boxes[boxId].insert(ch);
            }
        }

        return true;
    }
};