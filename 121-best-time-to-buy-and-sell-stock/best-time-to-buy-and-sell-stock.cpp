class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int min = INT_MAX;
        int maxPro = 0;
        int currentProfit = 0;

        for(int i=0; i<arr.size(); i++) {
            if(min > arr[i]) min = arr[i];

            currentProfit = arr[i] - min;
            maxPro = max(maxPro, currentProfit);
        }

        return maxPro;
    } 
};