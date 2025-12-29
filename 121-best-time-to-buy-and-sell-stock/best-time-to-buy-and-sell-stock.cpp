class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minP = prices[0];
        int maxProfit = 0;

        for(int i=0; i<n; i++) {
            minP = min(minP, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minP);
        }

        return maxProfit;
    }
};