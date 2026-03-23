class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        long maxR = 0;
        long addedCoins = 0;

        for(int coin:coins){
            while(coin > maxR + 1){
                maxR += maxR + 1;
                addedCoins++;
            }
            maxR += coin;
        }

        while(maxR < target) {
            maxR += maxR + 1;
            addedCoins++;
        }

        return addedCoins;
    }
};