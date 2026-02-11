class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadens algorithm
        int n = nums.size();
        int sum = 0;
        int maxSum = INT_MIN;

        for(int i=0; i<n; i++) {
            sum += nums[i];
            maxSum = max(sum, maxSum);

            // Reset sum value it if becomes -ve it wont do any good
            if(sum <= 0) sum = 0;
        }

        return maxSum;

        // prefix sum approach
    }
};