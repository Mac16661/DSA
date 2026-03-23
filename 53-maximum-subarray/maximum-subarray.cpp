class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadens algorithm
        // int n = nums.size();
        // int sum = 0;
        // int maxSum = INT_MIN;

        // for(int i=0; i<n; i++) {
        //     sum += nums[i];
        //     maxSum = max(sum, maxSum);

        //     // Reset sum value it if becomes -ve it wont do any good
        //     if(sum <= 0) sum = 0;
        // }

        // return maxSum;

        // prefix sum approach: We need to find the minimum prefix which we can substract form the current prefix to get the larget remainig

        int pref = 0;
        int minPref = 0;
        int ans = INT_MIN;

        for(int x : nums) {
            pref += x;
            ans = max(ans, pref - minPref);     // finding the minimum prefix 
            minPref = min(minPref, pref);
        }

        return ans;

    }
};