class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int first = INT_MAX, second = INT_MAX;
        int n = prices.size();

        for(int i=0; i<n; i++) {
            int val = prices[i];
            if(val < first) {
                second = first;
                first = val;
            }else if(val < second ) {
                second = val;
            }
        }
        // cout<<first<<" "<<second;

        int amt = second+first;
        return amt > money ? money: money-amt;
    }
};