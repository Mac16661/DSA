class Solution {
public:
    int helper(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        // Base case if any idx become < 0, i.e. there cannot be any more matching sub seq
        if (i < 0 || j < 0) 
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Match (doing similar to unbonded)
        if (text1[i] == text2[j])
            return dp[i][j] = 1 + helper(i-1, j-1, text1, text2, dp);

        return dp[i][j] = max(helper(i-1, j, text1, text2, dp), helper(i, j-1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n-1, m-1, text1 , text2, dp);
    }
};