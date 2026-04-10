class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int profit = 0;
        for (auto x:prices) {
            buy = min(buy, x);
            profit = max(profit, x - buy);
        }

        return profit;
    }
};