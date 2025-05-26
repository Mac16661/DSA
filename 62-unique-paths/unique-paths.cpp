class Solution {
public:
    int cntT=0;
    void helper(int col, int row, int m, int n, int cnt) {
        if(col == m-1 && row == n-1) {
            cntT++;
            return;
        }

        // go down
        if(col < m) {
            helper(col+1, row, m, n, cnt+1);
        }

        // go left
        if(row < n) {
            helper(col, row+1, m, n, cnt+1);
        }
    }

    int uniquePaths(int m, int n) {
    
        long long res = 1;
        int N = m + n - 2;
        int r = min(m - 1, n - 1);

        for(int i = 1; i <= r; i++) {
            res = res * (N - r + i) / i;
        }

        return res;
    }
};