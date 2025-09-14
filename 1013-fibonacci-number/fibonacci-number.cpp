class Solution {
public:
    // int fib(int n) {
        // if(n==0 || n==1) return n;

        // // return fib(n-1)+fib(n-2);
        // int a = 0;
        // int b = 1;

        // for(int i=0; i<n; i++) {
        //     int temp = a+b;
        //     a = b;
        //     b = temp;
        // }

        // return a;
    // }

    int dp[31];

    Solution() {
        fill_n(dp, 31, -1);
    }

    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = fib(n-1) + fib(n-2);
    }
};