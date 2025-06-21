class Solution {
public:
    int count = INT_MAX;
    bool isPalindrome(string s, int ind, int i) {
            while(ind <= i){
                if(s[ind] != s[i]) return false;
                ind++; i--;
            }
            return true;
    }

    void helper(string& s, int idx, int cuts) {
        if(idx == s.size()) {
            count = min(count, cuts-1);
            return;
        }

        for(int i=idx; i<s.size(); i++) {
            bool leftSide = isPalindrome(s, idx, i);
            // bool rightSide = isPalindrome(s, i, s.size()-1);

            if( leftSide ){
                
                helper(s, i+1, cuts+1);
                
            }
        }
    }

    int minCut(string s) {
        // if(isPalindrome(s,0,s.size()-1)) {
        //     // cout<<"h"<<endl;
        //     return 0;
        // }

        // int cuts = 0;
        // helper(s, 0, cuts);

        // return count;

        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            int minCuts = i;
            for (int j = 0; j <= i; ++j) {
                if (s[j] == s[i] && (j + 1 > i - 1 || isPalindrome[j + 1][i - 1])) {
                    isPalindrome[j][i] = true;
                    minCuts = (j == 0) ? 0 : min(minCuts, dp[j - 1] + 1);
                }
            }
            dp[i] = minCuts;
        }

        return dp[n - 1];
    }
};