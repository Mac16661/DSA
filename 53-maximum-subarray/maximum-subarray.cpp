class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // we just need to rely on prev state i-1
        // int n = nums.size();
        // int prev = nums[0];
        // int ans = nums[0];

        // for(int i=1; i<n; i++) {
        //     prev = max(nums[i], nums[i] + prev);
        //     ans = max(ans, prev);
        // }

        // return ans;

        int prefix = 0, minPrefix = 0, maxSum = INT_MIN;
        for (int x : nums) {
            prefix += x;
            maxSum = max(maxSum, prefix - minPrefix);
            minPrefix = min(minPrefix, prefix);
        }
        return maxSum;
    }
};