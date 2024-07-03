#include<bits/stdc++.h>
using namespace std;

bool wordSearch(vector<vector<char>> &board, string word, int m, int n, int ind, int row, int col) {

    if(ind == word.length()) return true;

    if (row < 0 || col < 0 || row == m || col == n || board[row][col] != word[ind] or board[row][col] == '!')
            return false;

    char c = board[row][col];
    board[row][col] = '!';

    bool up = wordSearch(board, word, m,n,ind+1, row-1, col);

    bool down = wordSearch(board, word, m,n, ind+1, row+1, col);

    bool left = wordSearch(board, word, m,n, ind+1, row, col-1);

    bool right = wordSearch(board, word, m,n, ind+1, row, col+1);

    board[row][col] = '!';

    return up || down || left || right;

}

bool exist(vector<vector<char>> &board, string word) {
    
    int m = board.size();
    int n = board[0].size();


    int index = 0;

    // This loop is searchig for the first charecter
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(word[0] == board[i][j]) {
                if(wordSearch(board, word, m, n, index, i, j)){
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board {{'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}};

    string word = "ABCB";

    bool res = exist(board, word);

    if (res) cout<<"matched"<<endl;
    else cout<<"not matched"<<endl;


    return 0;
}