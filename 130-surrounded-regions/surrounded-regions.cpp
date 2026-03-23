class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        visited[row][col] = true;

        if(board[row][col] == 'X') return;

        // Move in 4 directions up, down, left, right
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};

        for(int i=0; i<4; i++) {
            int rowx = row+x[i], coly = col+y[i];

            if(rowx >=0 && rowx <board.size() && coly >=0 && coly <board[0].size() && !visited[rowx][coly]) {
                dfs(rowx, coly, board, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // traversing top and bottom boundary
        for(int j=0; j<m; j++) {
            // top one
            if(!visited[0][j]) {
                dfs(0, j, board, visited);
            }
            
            // bottom row
            if(!visited[n-1][j]) {
                dfs(n-1, j, board, visited);
            }
        }

        for(int i=0; i<n; i++) {
            // first col
            if(!visited[i][0]) {
                dfs(i, 0, board, visited);
            }

            // last col
            if(!visited[i][m-1]) {
                dfs(i, m-1, board, visited);
            }   
        }

        // now just change the remaning 0 to x in board matrix
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j] && board[i][j]=='O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};