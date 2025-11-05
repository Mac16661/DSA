class Solution {
public:
    int cnt = 0;
    void helper(int n) {
        if(n < 0) {
            return;
        }

        if(n==0) {
            cnt++;
            return;
        }

        // take 1 step
        helper(n-1);

        // take 2 step
        helper(n-2);
    }

    int helperTop(int n, vector<int> &dp) {
        if(n < 0) return 0;
        if( n == 0) return 1;

        if(dp[n] != -1) return dp[n];

        int st1 = helperTop(n-1, dp);
        int st2 = helperTop(n-2, dp);

        return dp[n] = st1 + st2;
    }

    int climbStairs(int n) {
        // from curr step take any one of them-> 
        // 1. take 1 step 
        // 2. take 2 step
        // helper(n);
        // return cnt;
        vector<int> dp(n+1, -1);
        return helperTop(n, dp);
    }
};