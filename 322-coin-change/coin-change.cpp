class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // greedy wont work in this problem need dp
        // if(amount==0) return amount;
        // int count = 0;
        // int i=0;

        // sort(coins.begin(), coins.end(), greater<int>());

        // while(amount > 0 && i<coins.size()){
        //     cout<<amount<<endl;
        //     if(coins[i] <= amount){
        //         amount -= coins[i];
        //         count++;
        //     }else i++;
        // }

        // if(amount > 0) return -1;

        // return count;

        const int INF = 1e9;  // A large number representing "infinity"
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                if (dp[i - coin] != INF) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];        
    }
};