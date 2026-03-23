class Solution {
public:
    int dp[601][101][101]; 
    unordered_map <int, pair<int,int>> mp; // stores number of 0 & 1 for each string

    vector<int> cnt_mn(int i) {
        vector<int> ans(2, 0);
        auto it = mp[i];
        ans[0] = it.first;
        ans[1] = it.second;
        return ans;
    }

    // Doing dp optimizaton 
    int helper(int i, vector<string>& strs, int m, int n) {
        // base case 
        if(i == strs.size()) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];

        vector<int> cnt = cnt_mn(i);
        int zeros = cnt[0], ones = cnt[1];

        // Not taking current i
        int notTake = helper(i+1, strs, m, n);

        // Taking current i
        int take = 0;
        if(m >= zeros && n >= ones) {
            take = 1 + helper(i+1, strs, m-zeros, n-ones);
        }
        
        return dp[i][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        for(int i=0; i<strs.size(); i++){
            int z = 0, o = 0;
            for (auto j: strs[i]) {
                if(j=='0') z++;
                else o++;
            }
            mp[i] = make_pair(z, o);
        }
        memset(dp, -1, sizeof(dp));
        return helper(0, strs, m, n);
    }
};