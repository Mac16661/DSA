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

        // vector<int> dp(n+1, -1);
        // return helperTop(n, dp);

        // dp bottom up approach
        // vector<int> dp(n+1, 0);
        // dp[0] = 1;

        // for(int i=1; i<=n; i++) {
        //     int st1 = dp[i-1];
        //     int st2 = 0;
        //     if(i>1) st2 = dp[i-2];
        //     dp[i] = st1+st2;
        // }

        // return dp[n];

        // dp optimization
        if (n <= 2) return n;
        int prev2 = 1, prev1 = 2; // TODO: Here we are calculating naumber of distinct ways so we are effectively storing distinct ways form prev2 to end and distinct way from prev1 to end which is 1 and 2 respectively.

        for(int i=3; i<=n; i++) {
            int curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};